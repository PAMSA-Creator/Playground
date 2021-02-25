unsigned long newTime = 0;
unsigned long oldTime = 0;
unsigned long elapsedTime = 0;
unsigned int rpm = 0;
const unsigned int pulsesPerTurn = 20;
const int outputPin = 9;
const int interruptPin = 2;
const int interruptNumber = digitalPinToInterrupt(interruptPin);
volatile unsigned int pulses = 0;

void count(void){
  // Increment the pulse counter
  pulses++;
}

void setup() {
  // Start the serial interface
  Serial.begin(115200);

  // Define the interrupt pin as an input
  pinMode(interruptPin, INPUT);

  // Output a square wave signal on outputPin using the PWM functionality
  pinMode(outputPin, OUTPUT);
  analogWrite(outputPin, 127);

  // Attach the ISR, the count() function
  // Act on the falling edge of the interruptPin
  attachInterrupt(interruptNumber, count, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  newTime = millis();
  elapsedTime = newTime - oldTime;

  // When elapsed time is 1 second or more
  if(1000 <= elapsedTime) {
    // Stop the interrupt immediately
    detachInterrupt(0);

    // Calculate the rotation speed
    rpm = pulses * 60 / pulsesPerTurn;

    // Output some info on the terminal
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
