/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <HJoemNavi.h>
#include "Keyboard.h"
#include "Mouse.h"

int RECV_PIN = 11;
HJrecv hjrecv(RECV_PIN);
decode_results results;
unsigned int  cnt = 0;  // Счетчик подтверждения
unsigned int  cntc = 0;  // Счетчик подтверждения
unsigned long dvalue = 0;   // Decoded value [max 32-bits]
#define CNT   2         // Сколько раз нужно подтвердить декодированный символ
#define CNTC   10000         // Сколько раз нужно подтвердить декодированный символ
unsigned int mouse;


void setup()
{
//  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
//  Serial.println("Enabling HJin");
  hjrecv.enableHJIn(); // Start the receiver
//  Serial.println("Enabled HJin");
  Mouse.begin();
  Keyboard.begin();
}


void loop() {
  if (hjrecv.decode(&results)) {
    // здесь будем проверять символы джойстика
    switch(results.value) {
      case  0xf0bf8303: // [<--]
//        Serial.println("mouse left");
        Mouse.move(-40, 0);
        break;
      case  0xf0ef8243: // [-->]
//        Serial.println("mouse right");
        Mouse.move(40, 0);
        break;
      case  0xf0f78223: // [up]
//        Serial.println("mouse up");
        Mouse.move(0, -40);
        break;
      case  0xf0df8283: // [down]
//        Serial.println("mouse down");
        Mouse.move(0, 40);
        break;
      case  0xf85be191: // [<up]
//        Serial.println("mouse left-up");
        Mouse.move(-40, -40);
        break;
      case  0xf873e131: // [>up]
//        Serial.println("mouse right-up");
        Mouse.move(40, -40);
        break;
      case  0xf84fe1c1: // [<down]
//        Serial.println("mouse left-down");
        Mouse.move(-40, 40);
        break;
      case  0xf867e161: // [>down]
//        Serial.println("mouse right-down");
        Mouse.move(40, 40);
        break;
//      case  0xa0ffc207: // [enter]
//        Serial.println("mouse click");
//        break;
      default: {
        // А теперь кнопки
        switch(results.value) {
          case  0xf0fe8207: // [audio]
//            Serial.println(0xe2, HEX);
            Keyboard.write(0xE2);
            cnt++;
            break;
          case  0xf0fd820b: // [cancel] -> esc
//            Serial.println(0x1b, HEX);
            Keyboard.write(0x1B);
            cnt++;
            break;
          case  0xe0ffc303: // [map]
//            Serial.println(0x122, HEX);
            Keyboard.write(0x122);
            cnt++;
            break;
          case  0x60ffc20b: // [menu]
//            Serial.println(0x5d, HEX);
            Keyboard.write(0x5D);
            cnt++;
            break;
          case  0xe0ffc283: // [*)]
//            Serial.println(0xe7, HEX);
            Keyboard.write(0xE7);
            cnt++;
            break;
          case  0xe0ffc213: // [info]
//            Serial.println(0x06, HEX);
            Keyboard.write(0x06);
            cnt++;
            break;
          case  0xa0ffc207: // [enter]
//            Serial.println(0x0d, HEX);
            Keyboard.write(0x0D);
            cnt++;
            break;
          case  0xf0ffc3ff: // [<---]
//            Serial.println(0x25, HEX);
            Keyboard.write(0x25);
            cnt++;
            break;
          case  0xf0ffc303: // [-->]
//            Serial.println(0x27, HEX);
            Keyboard.write(0x27);
            cnt++;
            break;
        }
      }
    }
    hjrecv.resume(); // Receive the next value
    if(cnt > 0)   for(long i; i<100000000; i++) {;}
    cnt = 0;
  }
}




/*
void loop() {
  if (hjrecv.decode(&results)) {
    // здесь будем проверять символы джойстика

    // А теперь кнопки
    cntc = 0;
    if(results.value == dvalue) {
      cnt++;
//Serial.print("Cnt: "); Serial.println(cnt, DEC);
    } else {
      dvalue = results.value;
      cnt = 0;
    }
    hjrecv.resume(); // Receive the next value
  } else {
    if(dvalue > 0 && cnt >= CNT && hjrecv.isIdle()) {  // Кнопка отпущена
//Serial.print("Cntc: "); Serial.println(cntc, DEC);

      if(cntc > CNTC) {
        Serial.println(dvalue, HEX);  // отправляем в HID
        dvalue = 0;
        cnt = 0;
        cntc = 0;
      } else {
        cntc++;
      }
//    } else {
//      cntc = 0;
    }
  }
}
*/