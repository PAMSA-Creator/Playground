#ifndef _PWM_H
#define _PWM_H

#include<Arduino.h>
//#define _SERIAL_PRINT

const int PWMPin = 6;

void PWMSetup();
void PWMRun();

#endif  // _PWM_H