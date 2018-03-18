#include <Wire.h>
#include <Servo.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>

int servoPin1 = 10;
int servoPin2 = 9;

int previousAngle1 = 0;
int previousAngle2 = 0;

Servo servo1;
Servo servo2;

String inString = "";    // string to hold input

void setup() {
  pinMode(servoPin1, OUTPUT); 
  pinMode(servoPin2, OUTPUT); 

  // Begin the Serial at 9600 Baud
  Serial.begin(9600);

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop() {
  // Read serial input:
  while (Serial.avaizlable() > 0) {
    int inChar = Serial.read();
 
    
    inString += (char)inChar;
    
    if (inChar == '\n') {
      //https://stackoverflow.com/questions/11068450/arduino-c-language-parsing-string-with-delimiter-input-through-serial-interfa#14306981
      int first  = inString.indexOf(',');
      int second = inString.indexOf(',', first + 1);

      String servoPos1 = inString.substring(0, first);
      String servoPos2 = inString.substring(first + 1, second);
      
      int pos1 = servoPos1.toInt();
      int pos2 = servoPos2.toInt();

      int percent1 = pos1/320;
      int percent2 = pos2/240;

      int angletoadd1 = percent1*54;
      int angletoadd2 = percent2*41;      

      int currentAngle1 = previousAngle1 + angletoadd1;
      int currentAngle2 = previousAngle2 + angletoadd2;

      
            
//      Serial.print("Pos1: ");
//      Serial.print(servoPos1);
//      Serial.print(", Pos2: ");
//      Serial.print(servoPos2);
//      
      if(currentAngle1 <= abs(90) && abs(currentAngle1) >= 0){
        servo1.write(currentAngle1);
        previousAngle1 = currentAngle1;
      }else{
         servo1.write(previousAngle1);
      }
      
      if(currentAngle2 <= abs(90) && abs(currentAngle2) >= 0){
        servo1.write(currentAngle2);
        previousAngle2 = currentAngle2;
      }else{
         servo1.write(previousAngle2);
      }
      
//      // clear the string for new input:
      inString = "";g
    }
  }
}

//320 240
