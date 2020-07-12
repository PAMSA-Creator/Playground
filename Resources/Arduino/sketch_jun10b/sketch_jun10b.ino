void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char* string1;  // pointer to the first string
  char* string2;  // pointer to the second string
  int len = 0;    // length of string to read from input buffer
  int num = 0;    // number of bytes read from input buffer

  // ask for the first string
  Serial.println("Enter the first string!");
  // wait for the first string to be entered
  while(!Serial.available());
  // wait for all characters to be received
  delay(100);

  // check how many characters to read
  len = Serial.available();
  // show how many characters to read
  Serial.println(len);
  // dynamically allocate the memory to store the string
  string1 = new char[len];
  // read the string from input buffer
  num = Serial.readBytes(string1, len);

  // show the number of characters read from the input buffer
  Serial.println(num);
  // terminate the string with the null character to indicate the end
  string1[num] = 0;
  // print the string to show we got the right result
  Serial.println(string1);

  // Repeat the above for the second string
  Serial.println("Enter the second string!");
  while(!Serial.available());
  delay(100);
  len = Serial.available();
  Serial.println(len);
  string2 = new char[len];
  num = Serial.readBytes(string2, len);
  Serial.println(num);
  string2[num] = 0;
  Serial.println(string2);

  // Compare the strings and output the results of the strcmp function
  Serial.print("num = ");
  Serial.println(num);
  Serial.print("strcmp returned: ");
  Serial.println(strcmp(string1, string2));
  Serial.print("result = ");
  Serial.println(num == strcmp(string1, string2));
  
  delete(string1);
  delete(string2);
}
