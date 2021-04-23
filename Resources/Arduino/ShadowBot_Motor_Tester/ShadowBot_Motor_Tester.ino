/*
 * ShadowBot Motor Test
 * Test tool for the 4WD ShadowBot, a basic vehicle built with Arduino Uno and the ADA Fruit DCMotor Shield.
 * The software controls 4 x 5V geared DC motors from the common 4WD motor chassis robotics kit.
 * (https://www.jaycar.com.au/4-wheel-drive-motor-chassis-robotics-kit/p/KR3162)
 * It uses the Adafruit Motor Shield Library to control the electronic driver board (shield).
 * 
 * Allows a user to control the motors via the Serial interface
 * 8 = FORWARD
 * 2 = BACKWARD
 * 5 = STOP (CONTROLLED)
 * 0 = HALT
*/
#include <AFMotor.h>

AF_DCMotor motorFL(1);          // Front Left DC motor on M1
AF_DCMotor motorFR(2);          // Front Left DC motor on M2
AF_DCMotor motorBR(3);          // Front Left DC motor on M3
AF_DCMotor motorBL(4);          // Front Left DC motor on M4

// Set maximum operating speed
const int minSpeed = 80;
const int maxSpeed = 200;

// Function declarations
void speedUp(int arg=maxSpeed);
void slowDown(int arg=minSpeed);


void setup() {
  // Open the Serial port
  Serial.begin(115200);
  // Wait until configured correctly
  while(!Serial);

  // Set motor speeds
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
    if('8' == p | '2' == p) slowDown();
    speedUp();
  }
  else if('2' == c){
    motorFL.run(BACKWARD);
    motorFR.run(BACKWARD);
    motorBR.run(BACKWARD);
    motorBL.run(BACKWARD);
    if('8' == p | '2' == p) slowDown();
    speedUp();
  }
  else if('5' == c){
    slowDown();
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

/*
 * Function definitions
*/

// Used to ramp speed up
void speedUp(int arg){
  for (int i = 0; i < arg; i++) {
    motorFL.setSpeed(i);
    motorFR.setSpeed(i);
    motorBR.setSpeed(i);
    motorBL.setSpeed(i);
    delay(5);
  }
}

// Used to ramp speed down
void slowDown(int arg){
  for (int i = maxSpeed; i > arg; i--) {
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
