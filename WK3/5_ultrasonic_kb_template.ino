/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 3                          
> ULtrasonic musical keyboard. 
*/

const int pingPin = 4; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 2; // Echo Pin of Ultrasonic Sensor
const int piezoPin = 9;

//Tones
int notes[] = {
  262, //NOTE_C4
  294, //NOTE_D4
  330, //NOTE_E4
  349, //NOTE_F4
  392, //NOTE_G4
  440, //NOTE_A4
  494, //NOTE_B4
  523  //NOTE_C5
};

char* names[] = { " C", " D", " E", " F", " G", " A", " B" , " C5"};
const int noteDuration = 500; //Set default tone as 250ms
const int noteStep = 7; //Note range before moving to next step

//Function to play selected tone
void playTone(int idx)
{
  
}


void setup() {
  Serial.begin(115200); // Starting Serial Terminal
  pinMode(echoPin, INPUT);
}

void loop() {
  //Main loop
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  return 0.01745 * microseconds;
}