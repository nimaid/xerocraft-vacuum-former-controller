#include <Wire.h>

//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
#include "PCF8574.h"

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
PCF8574 pcf8574(0x20); // Set i2c address
int buttonPin = 2; //The Pin your button is attached to
float pressLength_milliSeconds = 0;//This value will be recorded in seconds

void setup()
{
  
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("    I2C lcd");
  lcd.setCursor(0,1);
  lcd.print("  (0x3F,16,2)");

    // Set pinMode to OUTPUT
  pcf8574.pinMode(P0, OUTPUT);
  pcf8574.pinMode(P1, OUTPUT);
  pcf8574.pinMode(P2, OUTPUT);
  pcf8574.pinMode(P3, OUTPUT);

  //Record *roughly* the tenths of seconds the button in being held down
  while (digitalRead(buttonPin) == LOW ){ 

    delay(100);  //if you want more resolution, lower this number 
    pressLength_milliSeconds = pressLength_milliSeconds + 100;   

    //display how long button is has been held
    
    lcd.println(pressLength_milliSeconds);

  }//close while

  


void loop()
