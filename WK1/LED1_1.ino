/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 

Arduino Workshop Series
Session 1                          

> Blink an LED via pin 11. 

*/


void setup()
{
  pinMode(11, OUTPUT);		//Set pin to output mode
}

void loop()
{
  digitalWrite(11, HIGH);	// Output HIGH @ pin 11
  delay(500); 				// Wait for 500 millisecond(s)
  digitalWrite(11, LOW);	// Output LOW @ pin 11
  delay(500); 				// Wait for 500 millisecond(s)
}