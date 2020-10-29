/*
     ________  ___   ___
    / __/ __ \/ _ | / _ \
   _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Practice
  > By 1487Quantum ( https://github.com/1487quantum )
  
  > Activity 2 (7 segment display, common Anode), Task B
  > =====================================================
  > Display the number 0 on the 7 segment display.


*/

void setup()
{
  for(int i=6; i<13; ++i){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);	//Turn on all the segment
  }
  digitalWrite(12, HIGH);	//Turn off segment g to display zero
}

void loop(){}