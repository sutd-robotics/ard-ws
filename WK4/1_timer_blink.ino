/*
   ________  ___   ___
  / __/ __ \/ _ | / _ \
  _\ \/ /_/ / __ |/ , _/
  /___/\____/_/ |_/_/|_|
  Arduino Workshop Series
  Session 4
  > LED blink at 2Hz using timers directly.
*/
const int ledPin = 13;
//Counter & compare value
const uint16_t t1_load = 0;
const uint16_t t1_comp = 31250;
volatile bool ledState = false;

void setup()
{
  pinMode(ledPin, OUTPUT);

  TCCR1A = 0;      //Reset Timer 1 Control Reg A

  //Set prescaler to 256
  TCCR1B |= (1 << CS12);
  TCCR1B &= ~(1 << CS11);
  TCCR1B &= ~(1 << CS10);

  //Reset timer 1 & set compare value
  TCNT1 = t1_load;
  OCR1A = t1_comp;

  //Enable Timer 1 compare interrupt
  TIMSK1 = (1 << OCIE1A);

  //Enable global interrupts
  sei();
}

ISR(TIMER1_COMPA_vect)              // interrupt service routine for overflow
{
  TCNT1 = t1_load;                                // Reset timer
  ledState = !ledState;       //Toggle state
  digitalWrite(ledPin, ledState);  //Turns LED ON and OFF
}

void loop()
{
  delay(500);
}
