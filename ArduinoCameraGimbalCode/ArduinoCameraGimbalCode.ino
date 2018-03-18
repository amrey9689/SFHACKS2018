/*
 Servo motor controller serial using adafruit motor shield v2.3
oran c
orabusiness@gmail.com
20170922

 Reads a serial input string until it sees a newline, then converts
 the string to a number if the characters are digits. converts to ints

 then tells servo motors one two to go to that position

 The circuit:
 arduino uno
adafruit motor shield v2.3
two hoby servos

plug shield into arduino
pluge into ports Servo 1 & Servo2
  */

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h> 


Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

int servoPin1 = 10;
int servoPin2 = 9;

int previousAngle1 = 0;
int previousAngle2 = 0;

int Init1 = 90;
int Init2 = 90;

int tol = 1;

Servo servo1;
Servo servo2;

int incoming[1];


//String inString = "";    // string to hold input

void setup() {

  
  pinMode(servoPin1, OUTPUT); 
  pinMode(servoPin2, OUTPUT); 

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
 // Serial.println("\n\nServo Posisitioner: ");
  //Serial.println();
  AFMS.begin(); 

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);


}
//0 do nothing, 1 positive, 2 negative
//Servo 2 X
//Servo 1 Y
void loop() {
  // Read serial input:
  servo1.write(Init1);
  servo2.write(Init2);
  while (Serial.available() >= 0) {
    //char inChar = '';
    char inChar = Serial.read();
    //for (int i = 0; i < 2; i++){
    //  incoming[i,j] = Serial.read();
    //}
    
    //if(pos1 <= 180 && pos1 >= 0){
        //previousAngle1 = pos1;
        //servo1.write(pos1);
      //}else{
         //servo1.write(previousAngle1);
        //Serial.print("pos1 Out of bounds :");
        //Serial.println(pos1);
      //}
    if (inChar == 'E'){
      //Move down, move right
      Init1 = Init1 + tol;
      Init2 = Init2 - tol;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar=='H'){
      //Move down, move left
      Init1 = Init1 + tol;
      Init2 = Init2 + tol;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar == 'B'){
      //Move down, stay
      Init1 = Init1 + tol;
      Init2 = Init2;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar == 'F'){
      //Move up, move right
      Init1 = Init1 - tol;
      Init2 = Init2 - tol;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar == 'I'){
      //Move up, move left
      Init1 = Init1 - tol;
      Init2 = Init2 + tol;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar == 'C'){
      //Move up, stay
      Init1 = Init1 - tol;
      Init2 = Init2;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar == 'D'){
      //Stay, move right
      Init1 = Init1;
      Init2 = Init2 - tol;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar == 'G'){
      //Stay, move left
      Init1 = Init1;
      Init2 = Init2 + tol;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    else if (inChar == 'A'){
      //Stay, stay
      Init1 = Init1;
      Init2 = Init2;
      //if(Init1 <= 180 && Init1 >=0){
        servo1.write(Init1);
      //}
      //if(Init2 <= 180 && Init2 >=0){
        servo2.write(Init2);
      //}
    }
    
    
    //servo1.write(inChar.toInt());
    
    
    // Serial.print(inChar);
    //Serial.print("\n");
    
    //inString += (char)inChar;
    
    //if (inChar == '\n') {
      //https://stackoverflow.com/questions/11068450/arduino-c-language-parsing-string-with-delimiter-input-through-serial-interfa#14306981
      //int first  = inString.indexOf(',');
      //int second = inString.indexOf(',', first + 1);

      //String servoPos1 = inString.substring(0, first);
      //String servoPos2 = inString.substring(first + 1, second);
      
      //int pos1 = servoPos1.toInt();
      //int pos2 = servoPos2.toInt();
           
      
      
      //if(pos1 <= 180 && pos1 >= 0){
        //previousAngle1 = pos1;
        //servo1.write(pos1);
      //}else{
         //servo1.write(previousAngle1);
        //Serial.print("pos1 Out of bounds :");
        //Serial.println(pos1);
      //}
      
      //if(pos2 <= 180 && pos2 >= 0){
        //previousAngle2 = pos2;
        //servo2.write(pos2);
      //}else{
        //servo1.write(previousAngle2);
        //Serial.print("pos2 Out of bounds :");
        //Serial.println(pos2);
      //}
      // clear the string for new input:
      //inString = "";
    //}
  }
}


