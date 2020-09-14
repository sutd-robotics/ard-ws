/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 

Arduino Workshop Series
Session 1                          

> Blink multiple LEDs via pin 11, 10, 6, 5, 3. 

*/

int led_pins[5] = {11,10,6,5,3};		//Declare pin array

void setup()
{
  for(int i=0; i<5; i++){
      pinMode(led_pins[i], OUTPUT);		//Iterate through the array & set them as output
  }
}

void loop()
{
//Iterate through the array & turn the LED(s) On & Off respectively
  for(int j=0; j<5; j++){
digitalWrite(led_pins[j], HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(led_pins[j], LOW);
  delay(500); // Wait for 500 millisecond(s)
  }
}
