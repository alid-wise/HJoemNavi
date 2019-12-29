// "Cancel" button D721C268

int O_PIN = 12;
int TM = 50; //mks takt
int PERIOD = 90; // ms
int symbol;

void setup() {
  pinMode(O_PIN,OUTPUT);

  Serial.begin(9600);

}

void loop() {
//  generate();
//  delay(PERIOD);

  while (Serial.available() > 0) {
    symbol = Serial.read();
    if(symbol == 0x0A) continue;
    Serial.println(symbol,HEX);

    switch (symbol) {
      case 0x71:  // q
        generate_audio();
        break;
      case 0x77:  // w
        generate_cancel();
        break;
      case 0x65:  // e
        generate_map();
        break;
      case 0x72:  // r
        generate_menu();
        break;
      case 0x74:  // t
        generate_ast();
        break;
      case 0x79:  // y
        generate_info();
        break;
      case 0x75:  // u
        generate_enter();
        break;
      case 0x69:  // i
        generate_left();
        break;
      case 0x6f:  // o
        generate_right();
        break;

      // joystik
      case 0x7a:  // z
        generate_jup();
        break;
      case 0x78:  // x
        generate_jdown();
        break;
      case 0x63:  // c
        generate_jleft();
        break;
      case 0x76:  // v
        generate_jright();
        break;
      case 0x62:  // b
        generate_jul();
        break;
      case 0x6e:  // n
        generate_jdl();
        break;
      case 0x6d:  // m
        generate_jur();
        break;
      case 0x2c:  // ,
        generate_jdr();
        break;
    }
    delay(PERIOD);
  }


}

void generate_audio() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1700);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1450);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(650);
  digitalWrite(O_PIN, LOW);
}

void generate_cancel() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(TM*33); //1650
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(TM*24); //1200
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(TM*40); //2000
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(TM*19); //950
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(TM*26); //1300  
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(TM*4);  //200
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(TM*9);  //450
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(TM*22); //1100
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(TM*4);  //200
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(TM*21); //1050
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(TM*4);  //200
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(TM*6);  //300
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(TM*8);  //400
  digitalWrite(O_PIN, LOW);
}

void generate_map() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1450);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
}

void generate_menu() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1050);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
}

void generate_ast() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(900);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1000);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
}

void generate_info() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(600);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(850);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(400);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
}

void generate_enter() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1450);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(900);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(650);
  digitalWrite(O_PIN, LOW);
}

void generate_left() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1700);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(750);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(900);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
}

void generate_right() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(800);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
}
//////////////////////////// joystik

void generate_jup() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(850);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(800);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(650);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(600);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
}

void generate_jdown() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(900);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1100);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(250);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1050);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
}

void generate_jleft() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(900);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(250);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1450);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
}

void generate_jright() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(600);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(250);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1000);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1150);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(450);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(800);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
}

void generate_jul() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(400);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(650);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
}

void generate_jdl() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(400);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1450);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(600);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1050);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
}

void generate_jur() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2100);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(600);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(400);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(400);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(650);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
}

void generate_jdr() {
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1650);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(2050);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(400);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(450);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(1200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(950);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(200);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(450);
  digitalWrite(O_PIN, LOW);
  delayMicroseconds(800);
  digitalWrite(O_PIN, HIGH);
  delayMicroseconds(200);
  digitalWrite(O_PIN, LOW);
}

