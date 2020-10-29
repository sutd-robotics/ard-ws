/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 3 (PIR Motion Sensor with LED), Task A
  > =====================================================
  > Read the value of the PIR Motion Sensor.


*/

#define PIR_PIN 2

int pRead = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  pRead = digitalRead(PIR_PIN);
  Serial.println(pRead);
  delay(100); 
}