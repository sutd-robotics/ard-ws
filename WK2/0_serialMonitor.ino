/*
   ________  ___   ___  
  / __/ __ \/ _ | / _ \ 
 _\ \/ /_/ / __ |/ , _/ 
/___/\____/_/ |_/_/|_| 
Arduino Workshop Series
Session 2                          
> Serial Monitor output of a for loop index. 
*/

void setup() {
  Serial.begin(9600); //Set baudrate as 9600 bits per second (bps)
}

void loop() {
  for(int i = 0 ; i <= 10; ++i) {
    Serial.print(i); 		//Print current index
    Serial.print(“\t”);
    Serial.println(i*i);	//Print i multiply i
    delay(1000); // wait for 1 second
  }
}
