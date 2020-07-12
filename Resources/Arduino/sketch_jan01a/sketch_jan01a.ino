#define R_PIN 11
#define B_PIN 10
#define G_PIN 9


void setup() {
  // put your setup code here, to run once:
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT); 
  analogWrite(R_PIN, 0);
  analogWrite(G_PIN, 0);
  analogWrite(B_PIN, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(R_PIN, 255);
  analogWrite(G_PIN, 0);
  analogWrite(B_PIN, 0);
  delay(1000);
  analogWrite(R_PIN, 0);
  analogWrite(G_PIN, 255);
  analogWrite(B_PIN, 0);
  delay(1000);
  analogWrite(R_PIN, 0);
  analogWrite(G_PIN, 0);
  analogWrite(B_PIN, 255);
  delay(1000);
}
