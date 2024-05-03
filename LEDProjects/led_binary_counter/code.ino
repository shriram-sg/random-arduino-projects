int zero = 10;
int one = 11;
int two = 12;
int three = 13;

void setup() {
  pinMode(zero, OUTPUT);
  pinMode(one, OUTPUT);
  pinMode(two, OUTPUT);
  pinMode(three, OUTPUT);
  Serial.begin(9600);
}

void displayBinary(int num) {
  if (num & 1) digitalWrite(zero, HIGH);
  if (num & 2) digitalWrite(one, HIGH);
  if (num & 4) digitalWrite(two, HIGH);
  if (num & 8) digitalWrite(three, HIGH);
}

void turnLEDOff() {
  digitalWrite(zero, LOW);
  digitalWrite(one, LOW);
  digitalWrite(two, LOW);
  digitalWrite(three, LOW);
}

void loop() {
  for (int i=0; i<16; i++) {
    displayBinary(i);
    delay(1000);
    turnLEDOff();
    delay(1000);
  }
}
