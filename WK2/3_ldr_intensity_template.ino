/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 2                          
> Light Intensity Display (Template). 
*/

//Pin setup
const int LEDS[4] = {12,11,10,9};
const int ldr_pin = A0;

int lightIntensity = 0;		//LDR value, intensity of LDR
void setup()
{
  Serial.begin(9600);	//Start serial
  //Setup pins
  for(int i=0;i<4;++i){
      pinMode(LEDS[i], OUTPUT);
  }
  pinMode(ldr_pin, INPUT);
}

void loop()
{
   //Read LDR
   
   //Process the LDR values
   
   //Set the LEDs accordingly
   
  
  //Print serial output
  Serial.println(lightIntensity);
}
