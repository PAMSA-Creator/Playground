/*
 * Testing bluetooth and interrupts
 */

#include <avr/interrupt.h>

volatile bool bFlag;
volatile int value;

void setup() {
  Serial.begin(9600);
  delay(100);

  // LED pin
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);

  // put your setup code here, to run once:
  cli();
  PCICR |= 0b00000100;    // Enables selected port interrupts port d
  PCMSK2 |= 0b00000001;   // Enables selected pins PD0
  sei();                  // Enable global interrupts

  bFlag = false;
  Serial.println("Ready to receive");
  interrupts();
}

void loop() {
  static bool bPreviousFlag = bFlag;
  int val = 0;

  if(bFlag != bPreviousFlag){
    noInterrupts();
    val = (bFlag == false) ? 0 : 255;
    interrupts();
    
    // put your main code here, to run repeatedly:
    // Set pin 13 to bState
    digitalWrite(13, val);
  
    // Write value to the serial interface
    Serial.println(value);

    bPreviousFlag = bFlag;
  }
}

ISR(PCINT2_vect){
  //bFlag = !bFlag;
  bFlag = (false == bFlag) ? true : false;
  value++;
}
