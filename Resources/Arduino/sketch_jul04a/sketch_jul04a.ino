#include <AFMotor.h>

AF_DCMotor motorFL(1);          // Front Left DC motor on M1
AF_DCMotor motorFR(2);          // Front Left DC motor on M2
AF_DCMotor motorBR(3);          // Front Left DC motor on M3
AF_DCMotor motorBL(4);          // Front Left DC motor on M4

// Set maximum operating speed
const int maxSpeed = 150;

void setup() {
  // Open the Serial port
  Serial.begin(115200);
  // Wait until configured correctly
  while(!Serial);

  // Seet motor speeds
  motorFL.setSpeed(maxSpeed);
  motorFR.setSpeed(maxSpeed);
  motorBR.setSpeed(maxSpeed);
  motorBL.setSpeed(maxSpeed);
  // Halt motors
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBR.run(RELEASE);
  motorBL.run(RELEASE);

  // Print instructions
  Serial.println("Hello I'm ShadowBot!");
  Serial.println("Here's how I work");
  Serial.println("Press '8' and I will go forward");
  Serial.println("Press '2' and I will go backward");
  Serial.println("Press '5' and I will slow down and stop");
  Serial.println("Press '0' and I will halt");
}

void loop() {
  // p will store the previous command
  static char p = 'x';
  // c will take its value from Serial.read()
  char c = 'x';

  // Wait for command on serial port
  while(!Serial.available());
  // Read a signle character
  c = Serial.read();

  // Act on specific command as explained in the instructions
  if('8' == c){
    motorFL.run(FORWARD);
    motorFR.run(FORWARD);
    motorBR.run(FORWARD);
    motorBL.run(FORWARD);
    if('8' == p | '2' == p) decelerate();
    accelerate();
  }
  else if('2' == c){
    motorFL.run(BACKWARD);
    motorFR.run(BACKWARD);
    motorBR.run(BACKWARD);
    motorBL.run(BACKWARD);
    if('8' == p | '2' == p) decelerate();
    accelerate();
  }
  else if('5' == c){
    decelerate();
    halt();
  }
  else if('0' == c){
    halt();
  }
  else{
    Serial.println("The command entered is incorrect");
    Serial.print("You entered: ");
    Serial.println(c);
  }

  // Store the command
  p = c;
}

// Used to ramp things up
void accelerate(){
  for (int i = 0; i < maxSpeed; i++) {
    motorFL.setSpeed(i);
    motorFR.setSpeed(i);
    motorBR.setSpeed(i);
    motorBL.setSpeed(i);
    delay(5);
  }
}

// Used to ramp things down
void decelerate(){
  for (int i = maxSpeed; i > 0; i--) {
    motorFL.setSpeed(i);
    motorFR.setSpeed(i);
    motorBL.setSpeed(i);
    motorBR.setSpeed(i);
    delay(5);
  }
}

// Halt the motors (stopping dead)
void halt(){
  motorFL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBR.run(RELEASE);
  motorBL.run(RELEASE);
}
