#include <Arduino.h>

#define GREEN 5
#define RED 6
#define BLUE 3


#define BUTTONINCPIN 10
#define BUTTONDECPIN 9

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTONINCPIN, INPUT_PULLUP);
  pinMode(BUTTONDECPIN, INPUT_PULLUP);
}

int lightValCurrent = 0;
int lightValBefore = 255;
int currentColor = 0; //0-red 1-blue 2-green
int prevColor = -1;

int returnColorConst(int code) {
  switch(code){
    case 0: return RED;
    case 1: return BLUE;
    case 2: return GREEN;
    default: return NULL;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(BUTTONINCPIN) == LOW && lightValCurrent != 255)
  {
    lightValCurrent++;
    lightValBefore--;
    analogWrite(returnColorConst(currentColor), lightValCurrent);
    analogWrite(returnColorConst(prevColor), lightValBefore);
    delay(10);

    if (lightValCurrent == 255) 
    {
      prevColor = currentColor;
      currentColor++;
      lightValCurrent = 0;
      lightValBefore = 255;
    }

    if (currentColor >= 3) currentColor = 0;

  }

  while(digitalRead(BUTTONDECPIN) == LOW && lightValCurrent != 0)
  {
    lightValCurrent--;
    lightValBefore++;
    analogWrite(returnColorConst(currentColor), lightValCurrent);
    analogWrite(returnColorConst(prevColor), lightValBefore);
    delay(10);

    if (lightValCurrent == 0) 
    {
      currentColor = prevColor;
      prevColor--;
      lightValCurrent = 255;
      lightValBefore = 0;
    }
  }

}