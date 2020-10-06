/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 4               
> Saving LED position with EEPROM
> 0: Left, 1:Center, 2:Right
*/

#include <EEPROM.h>

#define EEADDR 165 // Start location to write EEPROM data
static unsigned int SNUM = 37; //Special number to indicate whether pervious state was saved
static unsigned int ledLast, ledPos_saved;  //LED last would indicate whether its previously saved
int ledPos_current = 0;
int ledPos_prev = 3;

const int ledP[3] = {11, 10, 9}; //Would correspond to Left, center, right

//Button
const int btnP = A0;
int buttonState = 0;  //Initially not pressed

void setLED(int idx) {
  for (int j = 0; j < 3; ++j) {
    if (j != idx) {
      digitalWrite(ledP[j], LOW);
    } else {
      digitalWrite(ledP[idx], HIGH);
    }
  }
  delay(100);
}

void savPos(unsigned int idx) {
  int EEAddr = EEADDR;
  EEPROM.get(EEAddr, ledLast); //Check ledLast
  if (ledLast != SNUM) {
    EEPROM.put(EEAddr, SNUM);
    Serial.print("XXX");
  }
  EEAddr += sizeof(ledLast);
  EEPROM.put(EEAddr, idx);
  EEAddr += sizeof(idx);
  Serial.print("Saved POS NUM: "); Serial.println(idx);
}

void setup() {
  //Initialisation
  for (int i = 0; i < 3; ++i) {
    pinMode(ledP[i], OUTPUT);
  }
  pinMode(btnP, INPUT);
  Serial.begin(9600);
  Serial.println("EEPROM variable read and write.");

  // Read EEPROM
  int EEAddr = EEADDR;
  EEPROM.get(EEAddr, ledLast);
  EEAddr += sizeof(ledLast); //Shift to next item
  EEPROM.get(EEAddr, ledPos_saved);
  EEAddr += sizeof(ledPos_saved);
  //Debug
  Serial.print("LED LAST: "); Serial.println(ledLast);
  Serial.print("POS NUM: "); Serial.println(ledPos_saved);

  if (ledLast == SNUM) { //If equals SNUM, means it has recorded pervious value
    ledPos_current = ledPos_saved;
    setLED(ledPos_current);
  }
}

void loop() {
  buttonState = digitalRead(btnP);

  if (ledPos_prev != ledPos_current) {
    setLED(ledPos_current);
    ledPos_prev = ledPos_current;
  }

  if (buttonState) {
    if (ledPos_current < 2) {
      ++ledPos_current;
    } else {
      ledPos_current = 0;
    }
    Serial.println(ledPos_current);
    savPos(ledPos_current);
  }

  delay(150);
}