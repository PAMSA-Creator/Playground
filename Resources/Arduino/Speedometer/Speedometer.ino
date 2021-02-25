#define _TEST       // Comment out if using external input on interruptPin
#define METHOD 2    // METHOD can be either 1 or 2 only

unsigned long newTime = 0;
unsigned long oldTime = 0;
unsigned long elapsedTime = 0;
unsigned int rpm = 0;
const unsigned int pulsesPerTurn = 20;
const int interruptPin = 2;
const int interruptNumber = digitalPinToInterrupt(interruptPin);
volatile unsigned int pulses = 0;

#if defined(_TEST)
const int outputPin = 6;
#endif

/*
 * The count() function simply adds one to the pulses variable for each call
 * This function is to serve as the ISR for interrupts on the interruptPin
 */
void count(void){
  // Increment the pulse counter
  pulses++;
}

/*
 * The method1() function monitors the time elapsed between each loop
 * If the elapsed time is equal to or greater tahn 1 second then method1() calculates the rpm of the motor
 * If the millis() timer has wrapped around the take care of the exception
 */
void method1(){
  // put your main code here, to run repeatedly:
  newTime = millis();
  elapsedTime = newTime - oldTime;

  // When elapsed time is 1 second or more
  if(1000 <= elapsedTime) {
    // Stop the interrupt immediately
    detachInterrupt(interruptNumber);

    // Calculate the rotation speed
//    rpm = pulses * 60 / pulsesPerTurn;
  rpm = pulses;

    // Output the result on the terminal
    Serial.print("RPM =  ");
    Serial.println(rpm);
    
    // Reset the count
    pulses = 0;

    // Re-attach (enable) the interrupt to start counting again
    attachInterrupt(0, count, FALLING);

    // Capture the time immediately after enabling the interrupt
    oldTime = millis();
  }
  // If the time has wrapped around (occurs after approximately 50 days)
  else if (newTime < oldTime) {
    // Deal with the exception
    // Reset the number of pulses
    detachInterrupt(0);
    pulses = 0;
    attachInterrupt(interruptNumber, count, FALLING);

    // Capture the time immediately after enabling the interrupt
    oldTime = millis();
  }
}

/*
 * The method2() function works in a much simpler way than method1()
 * It waits for 1 second then performs the rpm calculation
 * This second method is may be used if proven to return better results than method1()
 */
void method2(){
  // Start by resetting the counter
  pulses = 0;

  // Attach/enable the interrupt
  attachInterrupt(interruptNumber, count, FALLING);

  // Wait 1 second exactly
  delay(1000);

  // Disable the interrupt
  detachInterrupt(interruptNumber);

  // Calculate the result
//  rpm = pulses * 60 / pulsesPerTurn;
  rpm = pulses;

  // Output the result on the terminal
  Serial.print("RPM =  ");
  Serial.println(rpm);
}

/*
 * The setup() function
 */
void setup() {
  // Start the serial interface
  Serial.begin(115200);

  // Define the interrupt pin as an input
  pinMode(interruptPin, INPUT);

#if defined(_TEST)
  // Output a square wave signal on outputPin using the PWM functionality
  pinMode(outputPin, OUTPUT);
  analogWrite(outputPin, 127);
#endif

#if (1 ==METHOD)
  // Attach the ISR, the count() function
  // Act on the falling edge of the interruptPin
  attachInterrupt(interruptNumber, count, FALLING);
#endif
}

/*
 * The loop() function
 */
void loop() {
#if (1 == METHOD)
  method1();
#elif (2 == METHOD)
  method2();
#endif
}
