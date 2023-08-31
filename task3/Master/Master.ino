#include <Wire.h>
#define button_1 4
#define button_2 5
#define slaveAddress 1
 

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
}

void loop ()
{
  int buttonState1 = digitalRead(button_1);
  int buttonState2 = digitalRead(button_2);

  Wire.beginTransmission(slaveAddress);
  Wire.write(buttonState1);
  Wire.write(buttonState2);
  Wire.endTransmission();

  delay(10);
}