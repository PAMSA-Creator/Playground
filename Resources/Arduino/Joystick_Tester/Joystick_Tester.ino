/*
 * Joystick tester
 * Works with Joystick XC4422 (Jaycar) 2-axis XY analogue joystick
 */

#include <Arduino.h>

#define ANALOG_RANGE  1024
#define JOYSTICK_Y_PIN  15

void setup() {
  pinMode(JOYSTICK_Y_PIN, INPUT);

  Serial.begin(115200);
}

void loop() {

  int vy = analogRead(JOYSTICK_Y_PIN) - (ANALOG_RANGE/2);
  Serial.print("Vy = ");
  Serial.println(vy);
  delay(500);
}
