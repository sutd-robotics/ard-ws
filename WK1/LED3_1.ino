/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 

Arduino Workshop Series
Session 1                          

> Bounce the light left & right. 

*/

int led_pins[5] = {11,10,6,5,3};		//Declare pins
int index = 0;							//Used to track the position of the light
bool isInverted = false;				//Determine the direction of the light, defaults to left

void setup()
{
  for(int i=0; i<5; i++){				//Pin setup
      pinMode(led_pins[i], OUTPUT);
  }
}

void lightLED(const int &num){			//Function to turn the LED On & Off
  digitalWrite(num, HIGH);
  delay(500); // Wait for 500 millisecond(s)
  digitalWrite(num, LOW);
  delay(500); // Wait for 500 millisecond(s)
}

void loop()
{
  lightLED(led_pins[index]);			//Run the function at the current LED position

  if((!isInverted&&index==4)||(isInverted&&index==0)){
   isInverted = !isInverted; 			//If position is at the beginning or end, flip the direction
  }
  if(!isInverted&&index<5){
    ++index;							//Increment only if the direction is moving right and the index is not at the end (5)
  }else if(isInverted&&index>-1){
        --index;						//Decrement only if the direction is moving left and the index is not at the beginning (0)
  }  
}

