/*
 * Testing bluetooth and interrupts
 */

#include <avr/interrupt.h> //we have to include this file to enable the interrupts

//Global variables
volatile bool bFlag; //volatile tells the compiler that this variable may change at any time and that the compiler should
                     // not optimize it
volatile int value;

void setup() {
  Serial.begin(9600);
  delay(100);

  // LED pin
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);

  // put your setup code here, to run once:
  cli();    //Disables global interrupts
  PCICR |= 0b00000100;    // Enables selected port interrupt (port D) 
  PCMSK2 |= 0b00000001;   // Enables selected pins PD0
  sei();   //Enable the global interrupts

  bFlag = false; 
  Serial.println("Ready to receive");
  interrupts();
}

void loop() {
  static bool bPreviousFlag = bFlag;
  int val = 0;

  if(bFlag != bPreviousFlag){ //If bFlag is toggled
    noInterrupts(); // N.B. In Arduino, Interrupts are enabled by default so we have to disable them before writing 
                    //time sensitive code
    val = (bFlag == false) ? 0 : 255; //255 means all 8 bits are ones
    interrupts();
    
    // put your main code here, to run repeatedly:
    // Set pin 13 to bState
    digitalWrite(13, val); //this will toggle the LED (from high to low and vice versa )every time the bFlag is toggled
  
    // Write value to the serial interface
    Serial.println(value);

    bPreviousFlag = bFlag;
  }
}

ISR(PCINT2_vect){
  //bFlag = !bFlag;
  bFlag = (false == bFlag) ? true : false; //this toggles the bFlag
  value++;
}
