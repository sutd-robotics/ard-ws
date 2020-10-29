/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 3 (PIR Motion Sensor with LED), Task C
  > =====================================================
  > Trigger the LED ON for 3s when motion is detected via interrupt method.


*/

#define latch_t 3000000

const byte PIR_PIN = 2;
const byte LED_PIN = 5;
volatile byte state = LOW;
volatile unsigned long duration;

void turnOnLED() {
  state = HIGH;
  duration = micros();
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), turnOnLED, RISING);
}

void loop() {
  Serial.println(micros() - duration);
  if (state && micros() - duration <= latch_t) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    state = LOW;
    digitalWrite(LED_PIN, LOW);
  }
}