#include <avr/sleep.h>

volatile int count;
volatile bool buttonPressed;
volatile int pin;

const int interruptPin = 7;       // Interrupt pin 7 [D7]
const int PCICR_MASK = 0b00000100;  // PCICR mask value to enable Port d interrupts (D0 - D7]
const int PCINT_MASK = 0b10000000;  // PCMSK mask value for pin 7 [PD7] on Arduino Uno
const int debounceTime = 20;      // Debounce time in milliseconds

// Pin Change Interrupt service routine
ISR (PCINT2_vect) {
  if(LOW == digitalRead(interruptPin)) {
    count++;
    buttonPressed = true;  
  }
  else
    buttonPressed = false;
}

void setup() {
  // Set the interrupt pin as an input
  pinMode(interruptPin, INPUT);

  // Set count to 0 and flag to false
  count = 0;
  buttonPressed = false;

  // Setup and start the serial interface
  Serial.begin(115200);
  delay(100); // Allow setup to complete

  // Enable interrupts
  enableInterrupts();  

  // Send a message to confirm program is ready
  Serial.println("Ready for interrupts");
  delay(100); // Allow transmission to complete

  // Put the device to sleep (low power mode)
  sleepNow();
}

void loop() {
  // An interrupt has occured and the device is awake
  
  // Disable the selected  interrupts triggering more interrupts
  //noInterrupts();     // disable all interrupts
  disableInterrupts();  // disable interrupts

  // Check if button has been pressed
  if(true == buttonPressed){

    // Upon interrupt triggered reset flag and print message
    buttonPressed = false;
    Serial.print("Interrupted ");
    Serial.print(count);
    Serial.println(" times");
    delay(100); // Allow the transmission to complete
  }
  
  //interrupts();     // Re-enable all interrupts
  enableInterrupts(); // Re-enable interrupts
  sleepNow(); // Put the device to sleep
}

/*
 * enableInterrupts()
 * Enables the relevant interrupts only
 */
void enableInterrupts() {
  cli();
  PCICR |= PCICR_MASK;    // Enables selected port interrupts
  PCMSK2 |= PCINT_MASK;   // Enables selected pins
  sei();
}

/*
 * disableInterrupts()
 * Disables only the interrutps used
 */
void disableInterrupts() {
  cli();
  PCICR &= !PCICR_MASK;   // Disable selected port interrupts
  PCMSK2 &= !PCINT_MASK;  // Disable selected pins
  sei();
  
}

/*
 * sleepNow()
 * Puts the device to sleep (low power mode)
*/
void sleepNow() {
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);   
  sleep_enable ();          // enables the sleep bit in the mcucr register
  sleep_mode ();            // here the device is actually put to sleep!!
}  // end of sleepNow

/*
 * testPin()
 * Used for debug purpose only to check the polarity of the pin and confirm that it changes state
*/
void testPin() {
  // Check the state of the interrupt pin
  int state = digitalRead(interruptPin);

  if(LOW == state) {
    Serial.println("LOW");
  }
  else {
    Serial.println("HIGH");
  }
}
