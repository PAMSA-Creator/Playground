int EN;
int In1;
int In2;

void init (int a , int b, int c){
  EN=a;
  In1=b;
  In2=c;
  }
void Run(int argSpeed, bool argDirection){
    // Set In1 and In2 based on argDirection
   
    if(false == argDirection){
        digitalWrite(In1, LOW);
        digitalWrite(In2, HIGH);
    }
    else{
        digitalWrite(In1, HIGH);
        digitalWrite(In2, LOW);
        Serial.println ("The direction is forward!");
    }
    //Setting the motor speed
analogWrite(EN, argSpeed);
Serial.println ("The speed is 255");
 int Sensor = analogRead (A0);
// Serial.println (A0);
 float voltage = Sensor * (5.0 / 1023.0);
 Serial.print("The Voltage is:");
 Serial.println (voltage);
}

void stop(){

    analogWrite(EN,0);
    digitalWrite(In1,LOW);
    digitalWrite(In2,LOW);
}
int motionCommand(unsigned char arg){
    // First is to breakdown the arg (message) into CID and speed
    // The lowest significant 4 bits are the speed information
    // The highest significant 4 bits are the command identifier itself

    // calculate from only 16 values available (from 0 to 15) when speed is 15 then argSpeed = 255 (increment is 17)
    char speed = (arg & 0x0F) * 17; //this is the max speed 1111 = 15 , 15*17= 255
    char CID = arg >> 4;

    // Run the command depending on CID
    switch (CID)
    {
        // Move forward is issued when the CID is 8 (0x8) (1000b)
        case 8: 
            Run (speed, true);
  
            Serial.println ("The car is moving forward!");
       
            break;
        // Move backward is issued when the CID is 2 (0010b)
        case 2:
            Run(speed, false);
      
            Serial.println("The car is moving backward!");
            break;
        // spin right is issued when the CID is 6 (0110b)
        case 6:
            Run(speed, false);
       
            Serial.println("The car is spinning right!");
            break;
        // spin left is issued when the CID is 4 (0100b)
        case 4:
            Run(speed, true);
           
            Serial.println("The car is spinning left!");
            break;
        // turn right forward is issued when the CID is 9 (1001b)
        case 9:
            Run(speed-17, true);
            
            Serial.println("The car is turning right forward!");
            break;
        //turn left forward is issued when the CID is 7 (0111b)
        case 7:
            Run (speed, true);
       
            Serial.println("The car is turning left forward!");
            break;
        //turn right backward    
        case 3:
            Run(speed-17 ,false);
            
            Serial.println("The car is turning right backward!");
            break;
        //turn left backward
        case 1:
            Run (speed,false);
           
            Serial.println("The car is turning left backward!");
            break;
        //stop is issued when the CID is 5 (0101b)
        case 5:
            stop();
            
            Serial.println("The car is stopping!");
            break;
        default:
            Serial.println("The car cannot respond to the command!");

    }
}
void setup() {
    
    init (10,9,8);
    Serial.begin (9600);
    // Initialise the enable pin as analogue output
    pinMode (EN,OUTPUT);
    // Initialise In1 pin as digital output
    pinMode (In1,OUTPUT);
    // Initialise In2 pin as digital output
    pinMode (In2,OUTPUT);
}
void loop() {
    Serial.println("Please Enter your command, you can enter values between 1 and 9!");
    // Check for user input on the serial interface
    while(Serial.available() == 0);
    // Read the input from the Serial interface and store in a 'command' variable
    unsigned char input = Serial.read();
    
    if((input >= '1') && (input <= '9')){
        // First we need to convert from the ASCII code to the correct command
        // 1. Get the decimal value of the character
        char value = input - '0';   /* Remember this trick */
        Serial.println("Converted to Decimal: ");
        Serial.print(value,DEC);
        Serial.println();                               
        // 2. Set the correct direction
        // Remember that the top-most bit is set to 1 for direction CID
        //char command = 0x80 | ((value << 4) & 0xF0);
        /* AH >> Here I made that so that the input values are still the same varying between 1 and 9 and I also changed their corresponding values in the CMot.cpp to be matching*/
        unsigned char command = (value<<4) & 0xF0;
        /* Change to the correct command required for the motion that we want to do */
        /* See CMOt for the correct command - translate from keyboard input to CID  
        for ex. 2 on the keyboard is opposed to 9 in the system*/
        // 3. Set the correct speed
        command |= 0x0F; //setting the maximum speed 1111 
        // Get the interface to CMot from p_itsCTest and call the motionCommand() function passing 'command' as argument
        Serial.println("Sending motionCommand: ");
        Serial.print(command, BIN);
        Serial.print(", ");
        Serial.print(command, DEC);
        Serial.println();
        //motionCommand(command);
        Run (255,true);
    }
    else {
        Serial.println ("That's an invalid value!");
    }
   
}
