#include <LiquidCrystal.h>

int button = 7;
int ledred = 8;
int ledgreen = 9;
int ledblue = 10;
int status = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup(){
pinMode(ledred, OUTPUT);
pinMode(ledgreen, OUTPUT);
pinMode(ledblue, OUTPUT);
pinMode(button, INPUT_PULLUP); // set the internal pull up resistor, unpressed button is HIGH

// set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("LED Color:");
}

void loop(){

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);

  
//a) if the button is not pressed the false status is reversed by !status and the LED turns on
//b) if the button is pressed the t66666666ttrrrue status is reveresed by !status and the LED turns off

  if (digitalRead(button) == true) {
    status = status+1;

    switch (status) {
      case 1:
          digitalWrite(ledred, true);
          digitalWrite(ledgreen, false);
          digitalWrite(ledblue, false);
          lcd.print("Red  ");
      break;
      case 2:
          digitalWrite(ledred, false);
          digitalWrite(ledgreen, true);
          digitalWrite(ledblue, false);
          lcd.print("Green");
      break;
      case 3:
          digitalWrite(ledred, false);
          digitalWrite(ledgreen, false);
          digitalWrite(ledblue, true);
          lcd.print("Blue ");
      break;
      default:
          digitalWrite(ledred, false);
          digitalWrite(ledgreen, false);
          digitalWrite(ledblue, false);
          lcd.print("Off  ");
          status = 0;
    }
    
  } 
  
  while(digitalRead(button) == true);
    delay(50); // keeps a small delay
  }
