#include "Toggle.h"

int togglePinState = LOW;

void toggleSetup() {
#if defined(_SERIAL_PRINT)
  Serial.begin(115200);
#endif
  // Set pin mode to OUTPUT
  pinMode(togglePin, OUTPUT);

  // Set initial pin state
  digitalWrite(togglePin, togglePinState);
}

void toggleRun() {
  // Toggle the state first
  togglePinState = (LOW == togglePinState) ? HIGH : LOW;

  // Set the pin to the new state
  digitalWrite(togglePin, togglePinState);

#if defined(_SERIAL_PRINT)
  // Output the state of the pin to terminal via the serial link
  Serial.print("Pin State: ");
  Serial.println(togglePinState, HEX);
#endif
}