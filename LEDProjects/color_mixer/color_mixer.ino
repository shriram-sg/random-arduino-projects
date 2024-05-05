int num;
String msg = "enter num: ";

int red = 3;
int green = 6;
int blue = 5;

int potenPin = A5;
int buttonPin = 8;
int colorSelection = 0; 

int colorVal;
int redVal;
int blueVal;
int greenVal;

#define DEBOUNCE_TIME 300
long button_press_timestamp = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(potenPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void change_color() {
  if (millis() - button_press_timestamp > DEBOUNCE_TIME) {
    if (colorSelection == 0) {
      redVal = colorVal;
    } 
    if (colorSelection == 1) {
      blueVal = colorVal;
    }
    if (colorSelection == 2) {
      greenVal = colorVal;
    }

    colorSelection++;
    button_press_timestamp = millis();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == 0) {change_color();}

  if (colorSelection == 3) {
    colorSelection=0;
  }

  colorVal = analogRead(potenPin) * 255. / 1023.;

  if (colorSelection == 0) {
    analogWrite(red, colorVal);
    analogWrite(blue, blueVal);
    analogWrite(green, greenVal);
  }
  if (colorSelection == 1) {
    analogWrite(red, redVal);
    analogWrite(blue, colorVal);
    analogWrite(green, greenVal);
  }
  if (colorSelection == 2) {
    analogWrite(red, redVal);
    analogWrite(blue, blueVal);
    analogWrite(green, colorVal);
  }
  
}
