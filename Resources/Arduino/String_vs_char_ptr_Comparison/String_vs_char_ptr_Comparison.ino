/*
 * String vs. char* comparison
 * Compile these two examples and compare the processing time, program storage space used and dynamic memory allocation
 */

#define _USE_STRING_CLASS
//#define _USE_CHAR_POINTER
void setup() {
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long start_time = micros();
#ifdef  _USE_STRING_CLASS
  String string1;
  String string2;
  String string3;
  String string4;
  String string5;
  String string6;
  String string7;
  String string8;
  String string9;
  String string10;
  String string11;
  String string12;
  String string13;
  String string14;
  String string15;
  String string16;
  String string17;
  String string18;
  String string19;
  String string20;
  String string21;
  String string22;
  String string23;
  String string24;
  String string25;
#endif
#ifdef  _USE_CHAR_POINTER
  char* string1;
  char* string2;
  char* string3;
  char* string4;
  char* string5;
  char* string6;
  char* string7;
  char* string8;
  char* string9;
  char* string10;
  char* string11;
  char* string12;
  char* string13;
  char* string14;
  char* string15;
  char* string16;
  char* string17;
  char* string18;
  char* string19;
  char* string20;
  char* string21;
  char* string22;
  char* string23;
  char* string24;
  char* string25;
#endif
  unsigned long stop_time = micros();

  Serial.print("Elapsed time: ");
  Serial.print(stop_time - start_time);
  Serial.println("us");
  delay(100);
  exit(0);
}
