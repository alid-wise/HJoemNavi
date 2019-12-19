/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <HJoemNavi.h>

int RECV_PIN = 11;
HJrecv hjrecv(RECV_PIN);
decode_results results;
unsigned int  cnt = 0;  // Счетчик подтверждения
unsigned long dvalue;   // Decoded value [max 32-bits]
#define CNT   3         // Сколько раз нужно подтвердить декодированный символ



void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling HJin");
  hjrecv.enableHJIn(); // Start the receiver
  Serial.println("Enabled HJin");
}

void loop() {
  if (hjrecv.decode(&results)) {
    // здесь будем проверять символы джойстика

    // А теперь кнопки
    if(results.value == dvalue) {
      cnt++;
    } else {
      dvalue = result.value;
      cnt = 0;
    }
    hjrecv.resume(); // Receive the next value
  } else {
    if(dvalue > 0 && cnt >= CNT) {  // Кнопка отпущена
      Serial.println(dvalue, HEX);  // отправляем в HID
      dvalue = 0;
      cnt = 0;
    }
  }
}
