/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 3                          
> Playing note with serial input. 
> Add the "pitches.h" file into Arduino (via the arrow on the right hand side, select "New Tab" and name it "pitches.h")
*/

#include "pitches.h"

const int piezoPin = 9;

// Declare 8 tones to be used:
int p_tone[] = {
  NOTE_C4,
  NOTE_D4,
  NOTE_E4,
  NOTE_F4,
  NOTE_G4,
  NOTE_A4,
  NOTE_B4,
  NOTE_C5
};

const int noteDuration = 500; //Set default tone as 250ms
char rx_byte = 0;      // Char received (1 char -> 1byte -> 8bit)

//Function to play selected tone
void playTone(char num)
{
  int idx = (int) num - 48;
  tone(piezoPin, p_tone[idx], noteDuration);    //Play tone for "noteDuration" long
}

void setup() {
  Serial.begin(115200);
  Serial.println("Enter number from 0 - 7:");
}

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character

    // check if a number was received
    if ((rx_byte >= '0') && (rx_byte <= '7')) {
      Serial.print("Playing tone: ");
      Serial.println(rx_byte);
      playTone(rx_byte);
    }
    else if ((rx_byte >= '0') && (rx_byte <= '7')) {

    }
    else {
      noTone(piezoPin);    // stop the tone playing:
      Serial.println("Invalid input!");
    }
  }
}
