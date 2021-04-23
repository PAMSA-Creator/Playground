#ifndef _TOGGLE_H
#define _TOGGLE_H

#include <Arduino.h>
//#define _SERIAL_PRINT

const int togglePin = 7;
extern int togglePinState;

void toggleSetup();
void toggleRun();

#endif  // _TOGGLE_H