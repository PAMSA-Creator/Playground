/*
 * RGB_LED_Tester
 * Works with KY-009 and KY-016 RGB 3 colour LEDs
 * The loop function switches individual LEDs one after the other (R, G, B) every 1 second
 */

#define B_PIN 11
#define G_PIN 12
#define R_PIN 13
// Arduino GND connected to LED board GND


void setup() {
  // Set the pin modes to output
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);

  // Switch all LEDs off
  analogWrite(R_PIN, 0);
  analogWrite(G_PIN, 0);
  analogWrite(B_PIN, 0);
}

void loop() {
  // Switch only R on
  analogWrite(R_PIN, 255);
  analogWrite(G_PIN, 0);
  analogWrite(B_PIN, 0);
  delay(1000);  // Wait 1 s
  
  // Switch only G on
  analogWrite(R_PIN, 0);
  analogWrite(G_PIN, 255);
  analogWrite(B_PIN, 0);
  delay(1000);  // Wait 1 s

  // Switch only B on
  analogWrite(R_PIN, 0);
  analogWrite(G_PIN, 0);
  analogWrite(B_PIN, 255);
  delay(1000); // Wait 1 s

  // All on
  analogWrite(R_PIN, 255);
  analogWrite(G_PIN, 255);
  analogWrite(B_PIN, 255);
  delay(1000); // Wait 1 s
}
