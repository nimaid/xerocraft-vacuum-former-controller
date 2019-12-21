//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

float pressLength_milliSeconds = 0;//This value will be recorded in seconds

uint8_t button_pin = 2; //The Pin your button is attached to. Can ONLY br 2 or 3 for interrupt to work!
uint8_t relay_pins[] = {3, 4, 5, 6, 7, 8, 9, 10}; // The pins for relays 0-7

void setup()
{
  Serial.begin(9600);
  
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("    I2C lcd");
  lcd.setCursor(0,1);
  lcd.print("  (0x3F,16,2)");

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(button_pin, INPUT_PULLUP);   // Keep in mind, when pin 2 has ground voltage applied, we know the button is being pressed
  
  // Set pinMode to OUTPUT
  for(int i=0; i<8; i++)
  {
    pinMode(relay_pins[i], OUTPUT);
  }

  // Setup button interrupts
  attachInterrupt(digitalPinToInterrupt(button_pin), 
                  button_ISR,
                  CHANGE);
  
  // Turn off all relays
  set_relays(0,0,0,0,0,0,0,0);
}

void loop()
{
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
}

void set_relay(uint8_t relay, bool pin_state)
{
  // Usage: set_relay(2, true);
  digitalWrite(relay_pins[relay], !pin_state);
}

void set_relays(bool in0, bool in1, bool in2, bool in3,
                bool in4, bool in5, bool in6, bool in7)
{
  // Usage: set_relays(0,1,1,0,0,0,1,1);
  bool pin_states[] = {in0, in1, in2, in3, in4, in5, in6, in7};
  for(int i=0; i<8; i++)
  {
    set_relay(i, pin_states[i]);
  }
}

#define NUM_STATES 8
int my_state = 0;
void my_func()
{
  switch (my_state)
  {
    case 0:
      set_relay(0, HIGH);
      break;
    case 1:
      set_relay(1, HIGH);
      break;
    case 2:
      set_relay(2, HIGH);
      break;
    case 3:
      set_relay(3, HIGH);
      break;
    case 4:
      set_relay(4, HIGH);
      break;
    case 5:
      set_relay(5, HIGH);
      break;
    case 6:
      set_relay(6, HIGH);
      break;
    case 7:
      set_relay(7, HIGH);
      break;      
  }
  
  my_state++;
  my_state %= NUM_STATES;
}


void button_ISR()
{
  if (digitalRead(button_pin) == LOW)
  {
    Serial.println("Button was pressed!");
    my_func();
  }
  else
  {
    Serial.println("Button was released!");
  }
}

