// This program is to control both the speed and direction of a motor using H-Bridge(L293D) IC in conjunction with Arduino.

// #include <EnableInterrupt.h> // when I comment this out the program is compiled ?????????????????????
 
 //#define potVal A0        // this pin is connected to the potentiometer
 #define Enable 9       // this pin is connected to pin 1 in the L293D to turn the motor on and off as well as controlling it's speed when it's used as PWM pin
 #define dirControl1  7  // this pin is connected to pin 7 in the L293D
 #define dirControl2  12  // this pin is connected to pin 2 in the L293D
 const byte onOffPin = 2;    // this pin is connected to ON/Off momentary switch (interrupt pin no.1)
 const byte directionPin = 3;   // this pin is connected to Direction momentary switch (interrupt pin no.2)
 volatile byte onOffState = LOW;  // setting these global variables of type volatile is recommended to be updated correctly 
 volatile byte directionState = LOW; //they are used to pass data between the ISR (i.e Interrupt Service Routine) & the main program (i.e LOOP)

 
void setup() {
  Serial.begin (9600);
  //pinMode (A0,INPUT);
  pinMode (Enable,OUTPUT);
  pinMode (dirControl1,OUTPUT);
  pinMode (dirControl2,OUTPUT);
  // Is there a need to specify interrupt pins as INPUT_PULLUP ? coz they are already connected to pull down resistors ?????????
  attachInterrupt(digitalPinToInterrupt(onOffPin), onOffMotor , RISING);
  attachInterrupt(digitalPinToInterrupt(directionPin), motorDirection, RISING);
}


void loop() {
  
// int motorSpeed = analogRead (potVal)/4 ;      // converting from (0-1023) range to (0- 255) range
  //digitalWrite (onOffPin , onOffState); //openning and closing the motor
  
  if (onOffState == HIGH){
   digitalWrite (Enable , HIGH);            // controlling the speed of the motor through PWM
    }
  else if (onOffState == LOW){
     digitalWrite (Enable , LOW);
     }

 
 
      
  //digitalWrite (directionPin, directionState); // controlling the direction of the motor 
  if (directionState == HIGH){
    digitalWrite (dirControl1 , HIGH);
    digitalWrite (dirControl2 , LOW);
    }
    else if (directionState == LOW){
      digitalWrite (dirControl1 , LOW);
      digitalWrite (dirControl2 , HIGH);
      }     
}

void onOffMotor (){
  onOffState =! onOffState ; // this is to toggle the On/Off state of the motor
  }

 void motorDirection () {
  directionState =! directionState ; //this is to toggle the direction state of the motor
    }
