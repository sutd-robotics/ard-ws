/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 1 (RGB LED), Task C
  > Turn each LED color ON & OFF with a time period of 1.02 seconds. (0.51s UP, 0.51s DOWN)


*/

#define DELAY 1
#define PI 3.1415927
#define MAX_BRIGHTNESS 255
#define T_PERIOD 1020


const int led_p[3] = {11, 9, 10}; //Red Green Blue

void setup()
{
  Serial.begin(115200);
  for (int i = 0; i < 3; ++i)
    pinMode(led_p[i], OUTPUT);
}

void runRamp(int pin) {
  for(int i=0; i<T_PERIOD; ++i)
    setLED(pin, i);
}

void setLED(int pin, int val) {
  int x_wave = (int) MAX_BRIGHTNESS*sin(0.25*val/(1.0*MAX_BRIGHTNESS)*PI);
  analogWrite(pin, x_wave);
  Serial.println(x_wave);
  delay(DELAY);
}

void loop()
{
  for (int i = 0; i < 3; ++i)
    runRamp(led_p[i]);
}
