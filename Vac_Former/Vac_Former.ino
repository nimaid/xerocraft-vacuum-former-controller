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
  
}

void loop()
{
  pcf8574.digitalWrite(P3, HIGH);
  delay(1000);
  pcf8574.digitalWrite(P3, LOW);
  delay(1000);
}
