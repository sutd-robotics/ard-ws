/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 2                          
> Fading an LED. 
*/

int ledPin = 3;    // LED connected to digital pin 3

void setup() {
  pinMode(ledPin, OUTPUT); //Declare as output mode
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);  // sets the value (0 to 255)
    delay(30); // wait for 30 milliseconds
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    delay(30); // wait for 30 milliseconds
  }
}

