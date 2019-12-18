// "Cancel" button D721C268

int O_PIN = 12;
int TM = 50; //mks takt
int PERIOD = 90; // ms
void setup() {
  pinMode(O_PIN,OUTPUT);
}

void loop() {
  generate();
  delay(PERIOD);
}

void generate() {
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
