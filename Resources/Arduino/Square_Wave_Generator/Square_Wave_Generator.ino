#include "Toggle.h"
#include "PWM.h"

void setup(){
    toggleSetup();
    PWMSetup();
}

void loop(){
    toggleRun();
}
