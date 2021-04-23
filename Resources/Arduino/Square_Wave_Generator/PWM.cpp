#include "PWM.h"

void PWMSetup() {
  // put your setup code here, to run once:
#if defined(_SERIAL_PRINT)
  Serial.begin(115200);
#endif

  // Set the PWM pin as output
  pinMode(PWMPin, OUTPUT);

  // Set PWM to 50% duty cycle
  analogWrite(PWMPin, 127);
}

void PWMRun() {
  // put your main code here, to run repeatedly:
#if defined(_SERIAL_PRINT)
  Serial.println("This method does not introduce any delay!");
  delay(1000);
#endif
}