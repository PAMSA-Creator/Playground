void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long start_time = 0;
  unsigned long stop_time = 0;
  unsigned long elapsed_time = 0;
  char c = 0;

  // Ask the user to enter something on the serial terminal
  Serial.println("Enter something on the terminal");

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
