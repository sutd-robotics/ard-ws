/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 1 (RGB LED), Task A
  > Turn each LED color ON & OFF with a time period of 4 seconds. (2s ON, 2s OFF) 

*/

#define DELAY 2000          //Define how long to delay LED
const int led_p[3] = {11, 10, 9}; //LED pins to be used: RED BLUE GREEN

void setup()
{
  for (int i = 0; i < 3; ++i) //Pin initialization
    pinMode(led_p[i], OUTPUT);
}

void setLED(int pin) {
  digitalWrite(pin, HIGH);
  delay(DELAY);
  digitalWrite(pin, LOW);
  delay(DELAY);
}

void loop()
{
  for (int i = 0; i < 3; ++i) //Run through the 3 colors
    setLED(led_p[i]);
}