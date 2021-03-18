// This program is to control both the speed and direction of a motor using H-Bridge IC in conjunction with Arduino.

//Declaring some constants for the pins and variables for storing the values on those pins.

 #define potVal A0        // this pin is connected to the potentiometer
 #define motorCon1 8   // this pin is connected to pin 7 in L293D to control direction of the motor
 #define motorCon2 9   // this pin is connected to pin 2 in L293D to control direction of the motor
 #define onOffSw1  7    // this pin is connected to the switch that will turn the motor on and off
 #define directionSw2 6     // this pin is connected to the switch that will control direction
 #define Enable 10       // this pin is connected to pin 1 in the L293D to turn the motor on and off 

 int Sw1state = 0;      // setting switches values to 0 as the normal state of the motor to be off
 int Sw2state = 0;
 int previousSw1 = 0;
 int previousSw2 =0;

 int motorOn =0;
 int motorSpeed=0;
 int motorDirection=1;
 
void setup() {
  Serial.begin (9600);  // this is to upload the sketch to the Arduino
  pinMode (potVal,INPUT);
  pinMode (motorCon1,OUTPUT);
  pinMode (motorCon2,OUTPUT);
  pinMode (onOffSw1,INPUT);
  pinMode (directionSw2,INPUT);
  pinMode (Enable,OUTPUT);
 // digitalWrite (Enable,LOW);
}

void loop() {
 Sw1state = digitalRead (onOffSw1);
 delay (1);
 Sw2state = digitalRead (directionSw2);
 motorSpeed = analogRead (potVal)/4;

 if (Sw1state != previousSw1){
  if (Sw1state == HIGH){
    motorOn = !motorOn ;
    }
  }
  if (motorOn == 1){
   analogWrite (Enable,motorSpeed);
   //digitalWrite (Enable , HIGH);
    }
  else{
    //analogWrite (Enable,0);
    digitalWrite (Enable , LOW);
    }

 if (Sw2state != previousSw2){
  if (Sw2state == HIGH){
    motorDirection =!motorDirection;
    }
  } 
  if (motorDirection == 1){
    digitalWrite (motorCon1,HIGH);
    digitalWrite (motorCon2,LOW);
    } 
   else {
     digitalWrite (motorCon1,LOW);
    digitalWrite (motorCon2,HIGH);
    }  

   previousSw1 = Sw1state;
   previousSw2 = Sw2state;
}
