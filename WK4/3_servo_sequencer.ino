/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 4               
> Sequencing servo with Serial monitor and EEPROM
*/

#include <Servo.h>
#include <EEPROM.h>

//Consts
#define SEQ_DELAY 1000
#define SEQ_SIZE 4

//EEPROM
int mem_addr = 100; /** the current address in the EEPROM (i.e. which byte we're going to write to next) **/

//Pins
const int pinServo = 6;
const int pinLEDRecord = 9;
const int pinLEDPlay = 8;

const int pinPot = A0; // analog pin used to connect the potentiometer

//Servo
Servo myservo; // create servo object to control a servo
int val; // variable to read the value from the analog pin
int sv_seq[SEQ_SIZE] = {};

//Sequence track
int seq = 0; //Defaults as 0, total of 4 sequences

//Serial
char rx_byte = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pinLEDRecord, OUTPUT);
  pinMode(pinLEDPlay, OUTPUT);
  myservo.attach(pinServo); // attaches the servo on pin 6 to the servo object
}

//Read potentiometer val
int readPot() {
  int ang = analogRead(pinPot);  // reads the value of the potentiometer (value between 0 and 1023)
  ang = map(ang, 0, 1023, 180, 0);  // scale it to use it with the servo (value between 0 and 180)
  return ang;
}

int recordSeq(int id, int val) {
  sv_seq[seq] = val; //Save seq to array

  String r_msg = (String) "[ " + (id + 1) + " / " + SEQ_SIZE + " ] Recorded: " + val;
  Serial.println(r_msg);

  digitalWrite(pinLEDRecord, HIGH);
  return ++id;
}

void resetSeq() {
  seq = 0;
  for (int k = 0; k < SEQ_SIZE; ++k) {
    sv_seq[k] = 0;
  }
}

void loop() {
  //Check for any input
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character

    switch (rx_byte) {
      case 'P':   //Play sequence
        Serial.println("Playing sequence...");
        digitalWrite(pinLEDPlay, HIGH);
        for (int i = 0; i < SEQ_SIZE; ++i) {
          myservo.write(sv_seq[i]);
          delay(SEQ_DELAY);
        }
        digitalWrite(pinLEDPlay, LOW);
        break;
      case 'R':   //Record sequence
        val = readPot();
        if (seq < SEQ_SIZE) {
          seq = recordSeq(seq, val);
        } else {
          Serial.println("Sequence is full! Empty or save the sequence 1st...");
        }
        break;
      case 'T':   //Test current position
        val = readPot();
        Serial.print("Testing: ");
        Serial.println(val);
        myservo.write(val); // sets the servo position according to the scaled value
        break;
      case 'S':   //Save the recorded sequence
        if (seq == SEQ_SIZE) {
          EEPROM.put(mem_addr, sv_seq);
          Serial.println("Seq saved!");
        } else {
          Serial.print("Sequence not complete: ");
          Serial.println(seq);
        }
      case 'C':
        resetSeq(); //Reset sequence array
        Serial.println("Cleared current sequence!");
        break;
      case 'L':   //Save the recorded sequence
        EEPROM.get(mem_addr, sv_seq);
        for (int j = 0; j < SEQ_SIZE; ++j) {
          Serial.print(sv_seq[j]);
          Serial.print(" ");
        }
        Serial.println("Seq loaded!");
        break;

      default:
        Serial.println("Invalid command");
    }

  } // end: if (Serial.available() > 0)
  digitalWrite(pinLEDRecord, LOW);
  digitalWrite(pinLEDPlay, LOW);

  delay(15);
}