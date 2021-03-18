// this program is to control a DC motor using a momentary switch and a mosfet 
// declaring some constants and variables

int const pushButton =2;
int const mosGate = 9;
int Sw = 0;

void setup() {
 Serial.begin (9600); 
 pinMode (pushButton,INPUT);
 pinMode (mosGate,OUTPUT);

}

void loop() {
  Sw = digitalRead (pushButton);
  if (Sw == HIGH){
    digitalWrite (mosGate,HIGH);
    }
    else {
      digitalWrite (mosGate,LOW);
      }
}
