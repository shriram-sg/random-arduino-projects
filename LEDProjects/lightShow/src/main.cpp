#include <Arduino.h>

#define REDLIGHT 3
#define GREENLIGHT 6
#define BLUELIGHT1 4
#define BLUELIGHT2 5

#define RGBRED 9
#define RGBGREEN 10
#define RGBBLUE 11

bool turnoff = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDLIGHT, OUTPUT);
  pinMode(GREENLIGHT, OUTPUT);
  pinMode(BLUELIGHT1, OUTPUT);
  pinMode(BLUELIGHT2, OUTPUT);
  pinMode(RGBRED, OUTPUT);
  pinMode(RGBBLUE, OUTPUT);
  pinMode(RGBGREEN, OUTPUT);
}

void loop() {
  if (!turnoff)
  {
    for (int i = 0; i<=255; i++)
    {
      analogWrite(REDLIGHT, i);
      analogWrite(RGBRED, i);
      delay(10);
    }

    for (int i = 0; i<=255; i++)
    {
      analogWrite(REDLIGHT, 255-i);
      analogWrite(RGBRED, 255-i);
      analogWrite(GREENLIGHT, i);
      analogWrite(RGBGREEN, i);
      delay(10);
    }

    for (int i = 0; i<=255; i++)
    {
      analogWrite(GREENLIGHT, 255-i);
      analogWrite(RGBGREEN, 255-i);
      analogWrite(BLUELIGHT1, i);
      analogWrite(BLUELIGHT2, i);
      analogWrite(RGBBLUE, i);
      delay(10);
    }

    for (int i = 0; i<=255; i++)
    {
      analogWrite(GREENLIGHT, i);
      analogWrite(REDLIGHT, i);
      analogWrite(RGBGREEN, i);
      analogWrite(RGBRED, i);
      delay(10);
    }

    for (int i = 0; i<=255; i++)
    {
      analogWrite(GREENLIGHT, 255-i);
      analogWrite(REDLIGHT, 255-i);
      analogWrite(BLUELIGHT1, 255-i);
      analogWrite(BLUELIGHT2, 255-i);
      analogWrite(RGBGREEN, 255-i);
      analogWrite(RGBBLUE, 255-i);
      analogWrite(RGBRED, 255-i);
      delay(20);
    }
    turnoff = true;
  }
  
}