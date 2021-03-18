
//This program is to control both DC motors of the robocar using the 1293H-Bridge Controller and Arduino UNO

#define M1EN 9 //This Arduino Pin is connected to Pin 1 in the H-bridge to control M1 speed
#define M11A 3 //This Arduino Pin is connected to Pin 2 in the H-bridge to control M1 direction
#define M12A 2 //This Arduino Pin is connected to Pin 7 in the H-bridge to control M1 direction
/*#define M2EN 10 //This Arduino Pin is connected to Pin 9 in the H-bridge to control M2 speed
#define M23A 9 //This Arduino Pin is connected to Pin 10 in the H-bridge to control M2 direction
#define M24A 8 //This Arduino Pin is connected to Pin 8 in the H-bridge to control M2 direction

/*#define Rx 0 //This is the Rx pin which will receive the instructions from the user */
char Dir = 0; //that is the char variable that will hold the desired direction
int Speed; //this variable should hold the analouge speed value

/*#define M1/Dir 2
#define M1/Speed 3
#define M2/Dir 4
#define M2/Speed 5*/

//Functions Declaration & definition
void Forward(){
  analogWrite (M1EN,255); //Max speed
  //analogWrite (M2EN,HIGH); //Max speed
  digitalWrite (M11A,HIGH);
  digitalWrite (M12A,LOW);
 // digitalWrite (M23A,HIGH);
 // digitalWrite (M24A,LOW);
  Serial.println ("The RoboCar is moving Forward !");
  }

/*void Backward() {
  analogWrite (M1EN,HIGH);
  analogWrite (M2EN,HIGH);
  digitalWrite (M11A,LOW);
  digitalWrite (M12A,HIGH);
  digitalWrite (M23A,LOW);
  digitalWrite (M24A,HIGH);
  Serial.println ("The RoboCar is moving Backward !");
  }

void Right() {
  digitalWrite (M1EN,LOW);
  digitalWrite (M2EN,HIGH);
  digitalWrite (M23A,HIGH);
  digitalWrite (M24A,LOW);
  Serial.println ("The RoboCar is moving RIGHT !");
  }

void Left(){
  digitalWrite (M1EN,HIGH);
  digitalWrite (M2EN,LOW);
  digitalWrite (M11A,HIGH);
  digitalWrite (M12A,LOW);
  Serial.println ("The RoboCar is moving LEFT !");
  }

void Stop(){
  digitalWrite (M1EN,LOW);
  digitalWrite(M2EN,LOW);
  Serial.println ("The RoboCar is in STOP mode !");
  }
*/
void setup() {
Serial.begin (115200);
//pinMode (Rx,INPUT);
pinMode (M1EN, OUTPUT);
pinMode (M11A,OUTPUT);
pinMode (M12A,OUTPUT);
//pinMode (M2EN,OUTPUT);
//pinMode (M23A,OUTPUT);
//pinMode (M24A,OUTPUT);
}

void loop() {
while (Serial.available()==0 ){
 
  }
   Dir = Serial.read() ;
delay(1);

if (Dir == 'F'){
  Forward();
  }

 /*if(Dir == 'B'){
  Backward();
  }

  if(Dir == 'R'){
  Right();
  }

  if(Dir == 'L'){
  Left();
  }

  if (Dir == 'S'){
    Stop();
    }*/
}
