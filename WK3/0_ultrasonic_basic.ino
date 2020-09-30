/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 3                          
> Distance measurement with ultrasonic sensor. 
*/

const int pingPin = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor

void setup() {
  Serial.begin(115200); // Starting Serial Terminal
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, dist_cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);  //Wait 2us before sending HIGH
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10); //Wait 10us before sending LOW
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  dist_cm = microsecondsToCentimeters(duration);
  if (dist_cm < 400) {
    Serial.print(dist_cm);
    Serial.println(" cm");
  }
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return 0.01745 * microseconds;
}
