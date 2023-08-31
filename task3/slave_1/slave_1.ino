#include <Wire.h>
#define led 6

// there is an issue i don't know what it is 


void setup()
{
  Wire.begin(1);
  Serial.begin(9600);
  Wire.onReceive(receiveResponse);
  pinMode(led, OUTPUT);
}

void loop ()
{
}

void receiveResponse (int n)
{
  if (Wire.available() ){
    int buttonState1 = Wire.read();
    int buttonState2 = Wire.read();
    
    int intensity = 0;

    if (buttonState1 == 1 && buttonState2 == 0){
       intensity = 128;
       Serial.println("Vector focused");
    }
    else if (buttonState1 == 0 && buttonState2 == 1){   
      intensity = 192;
      Serial.println("Vector distracted");
    }
    else if (buttonState1 == 1 && buttonState2 == 1){   
      intensity = 255;
      Serial.println("Glitch");
    }
    analogWrite(led, intensity);

    delay(10);    
  }
}
