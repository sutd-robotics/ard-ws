/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 3 (PIR Motion Sensor with LED), Task B
  > =====================================================
  > Trigger the LED ON for 3s when motion is detected via polling method.


*/

#define PIR_PIN 2
#define LED_PIN 5

int pRead=0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void turnOnLED(){
  digitalWrite(LED_PIN,HIGH);
  delay(3000);
  digitalWrite(LED_PIN,LOW);
  delay(1);
}


void loop()
{
  pRead = digitalRead(PIR_PIN);
  if(pRead)
    turnOnLED();
  delay(100); 
}