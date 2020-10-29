/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 2 (7 segment display, common anode), Task A
  > =====================================================
  > The common anode 7 segment display uses a inverted logic: A LOW would turn on the segment,
  > whereas HIGH would turn it off. This task would be used to determine which pin corresponds
  > to which segment.


*/

void setup() {
  for (int i = 6; i < 13; ++i) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);	//Turn off all the segment
  }
}

void loop() {
  for (int i = 6; i < 13; ++i) {
  digitalWrite(i, LOW);		//Turn on segment
  delay(500); 
  digitalWrite(i, HIGH);	//Turn off segment
  delay(500);
  }
}