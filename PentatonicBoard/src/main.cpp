#include <Arduino.h>
#include <pitches.h>

const int C_MAJ_PENT[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4};
const int C_MAJ_PENT_HIGH[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_A5};

// 2 sensor
// 12 active buzzer

void setup() {
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
}

int getNoteIndex(int buttonIndex)
{
  switch(buttonIndex)
  {
    case 11: return 0;
    case 10: return 1;
    case 9: return 2;
    case 6: return 3;
    case 5: return 4;
  }
}

void loop() {
  while(digitalRead(11) == LOW)  
  {
    if (digitalRead(2) == LOW) tone(13, C_MAJ_PENT_HIGH[getNoteIndex(11)]);
    else tone(13, C_MAJ_PENT[getNoteIndex(11)]);
  }
  while(digitalRead(10) == LOW)
  {
    if (digitalRead(2) == LOW) tone(13, C_MAJ_PENT_HIGH[getNoteIndex(10)]);
    else tone(13, C_MAJ_PENT[getNoteIndex(10)]);
  }
  while(digitalRead(9) == LOW)
  {
    if (digitalRead(2) == LOW) tone(13, C_MAJ_PENT_HIGH[getNoteIndex(9)]);
    else tone(13, C_MAJ_PENT[getNoteIndex(9)]);
  }
  while(digitalRead(6) == LOW)
  {
    if (digitalRead(2) == LOW) tone(13, C_MAJ_PENT_HIGH[getNoteIndex(6)]);
    else tone(13, C_MAJ_PENT[getNoteIndex(6)]);
  }
  while(digitalRead(5) == LOW)
  {
    if (digitalRead(2) == LOW) tone(13, C_MAJ_PENT_HIGH[getNoteIndex(5)]);
    else tone(13, C_MAJ_PENT[getNoteIndex(5)]);
  }
  noTone(13);
}