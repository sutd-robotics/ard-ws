/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 3                          
> Piezo clicking sound. 
*/

int piezoPin = 9; // select the input pin for Piezo

void setup() {
  pinMode(piezoPin, OUTPUT); //Set serial port for communication
}

void loop() {
  digitalWrite(piezoPin, HIGH);
  delay(500);      //Wait for 500ms
  digitalWrite(piezoPin, LOW);
  delay(500);      //Wait for 500ms
}
