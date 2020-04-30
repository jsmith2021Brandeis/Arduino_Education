/* reads the light level, if light level is high vibrates vibrotactor

*/

//the port of the vibrator
int vibPin=2;
//variable which stores the low light level for calibration
int lowLightLevel;
//variable which stores the current calibrated light level
int lightLevel;

//runs once
void setup() {
  
  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  while(!Serial){}
  pinMode(vibPin, OUTPUT);
  //print message asking user to turn lights off
  Serial.println("Photoresistor/Light Sensor Example, please turn lights off for calibration");
  //wait x milliseconds
  delay(8000);  
  Serial.println("Program will print calibrated light level, try turning lights on and off");
  //take initial reading to calibrate the photoresistor, with a margin of error 
  lowLightLevel=analogRead(A0)-3;
}

//runs many times
void loop() {
  //get the light level by substracting the current raw reading from the dark level
   lightLevel=analogRead(A0)-lowLightLevel;
   //print the light level
   Serial.println(lightLevel);
  //vibrates if distance is within range
  if (lightLevel > 10) {
    digitalWrite(vibPin, HIGH);   
  //otherwise turns fibrator off and waits x milliseconds
  } else {                  
    digitalWrite(vibPin, LOW);    
  }
  delay(500);
}
