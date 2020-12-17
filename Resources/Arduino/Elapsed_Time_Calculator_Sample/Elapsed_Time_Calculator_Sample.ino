/*
 * Elapsed time calculator sample code
 * The calculation of the elapsed time in this code takes into consideration the possibility of a wrap around.
 * A wrap around occurs when the timer reaches the limit of its count and goes back to zero.
 * At this moment the stop time will seem to have occured a long time before the start time.
 * To compensate and get the correct results one needs to count from start time to the max value of the timer then add the stop time.
 */

void setup() {
  // Start the Serial link @ 115200 bauds
  Serial.begin(115200);
}

void loop() {
  // Declare local variables
  unsigned long start_time = 0;   // Start time
  unsigned long stop_time = 0;    // Stop time
  unsigned long elapsed_time = 0; // Calculated period between start and stop
  char c = 0;                     // Character received

  // Ask the user to enter something on the serial terminal
  Serial.println("Enter something on the terminal - Only one character at a time please!");

  // Start the timer
  start_time = micros();
  
  // Wait until something came on the terminal
  while(!Serial.available());
  // Read the character(s) to clear the buffer for the next loop
  c = Serial.read();  // Only read one character for this test (only input one character at a time please)
  
  // Stop the timer straight away
  stop_time = micros();
  
  // Calculate the time elapsed
  elapsed_time = (stop_time > start_time) ? (stop_time - start_time) : (0xFFFFFFFF - start_time + stop_time);

  // Output the results
  Serial.print("character read: ");
  Serial.println(c);
  Serial.print("start_time = ");
  Serial.println(start_time);
  Serial.print("stop_time = ");
  Serial.println(stop_time);
  Serial.print("elapsed_time = ");
  Serial.println(elapsed_time);
}
