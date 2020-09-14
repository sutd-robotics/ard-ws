/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 

Arduino Workshop Series
Session 1                          

> Blink multiple LEDs via pin 11, 10, 6, 5, 3. 

*/

void setup()
{
  //Setup the pins as output
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
//Turn the LED(s) On & Off one after another, repeating the sequence once the LED has lighted
  digitalWrite(11, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(11, LOW);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(10, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(10, LOW);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(6, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(6, LOW);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(5, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(5, LOW);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(3, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(3, LOW);
  delay(500); // Wait for 500 millisecond(s)
}
