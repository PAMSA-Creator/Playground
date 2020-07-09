void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
/*  
  char* string1;
  char* string2;
  char string1[]="";
  char string2[]="";
  int len = 0;
  int numBytesRead = 0;
*/
  String string1;
  String string2;

  Serial.println("Enter the first string");

  // Wait for the first string
  while(0 == Serial.available());

//  delay(100);
  string1 = Serial.readString();
/*
  // Get the length of the first string
  len = Serial.available();
  Serial.print("len ");
  Serial.println(len);
  // Read the first string
  numBytesRead = Serial.readBytes(string1, len);
  Serial.print("numBytesRead ");
  Serial.println(numBytesRead);
*/
  // Print it to check that we got it right
  Serial.println(string1);

  Serial.println("Enter the second string");

  // Wait for the second string
  while(0 == Serial.available());

//  delay(100);
  string2 = Serial.readString();
/*  
  len = Serial.available();
  Serial.print("len ");
  Serial.println(len);
  // Read the first string
  numBytesRead = Serial.readBytes(string2, len);
  Serial.print("numBytesRead ");
  Serial.println(numBytesRead);
*/  
  // Print it to check that we got it right
  Serial.println(string2);

  // Compare the strings
  Serial.print("strcmp resulted in ");
//  Serial.println(strcmp(string1, string2));
  Serial.println(string2.equals(string1));
}
