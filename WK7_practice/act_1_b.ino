/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 1 (RGB LED), Task B
  > Turn each LED color ON & OFF with a time period of 2 seconds. (1s UP, 1s DOWN)

*/

#define DELAY 4
#define MAX_BRIGHTNESS 250

const int led_p[3] = {10, 11, 9}; //Blue Red Green

void setup()
{
  Serial.begin(115200);        //Setup Serial Monitor, for debugging
  for (int i = 0; i < 3; ++i)
    pinMode(led_p[i], OUTPUT);
}

void runRamp(int pin) {
  int i{0};                       // Index tracker
  while (i < MAX_BRIGHTNESS) {    //Ramp Up brightness
    setLED(pin, i);
    ++i;
  }
  while (i > 0) {                 //Ramp Down Brightness
    setLED(pin, i);
    --i;
  }
}

void setLED(int pin, int val) {
  analogWrite(pin, val);
  Serial.println(val);    //Print LED Value
  delay(DELAY);
}

void loop()
{
  for (int i = 0; i < 3; ++i)
    runRamp(led_p[i]);
}