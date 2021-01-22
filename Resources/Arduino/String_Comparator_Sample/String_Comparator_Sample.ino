/*
 * Simple string comparison sample code
 * _TEST_1 uses the String class
 * _TEST_2 uses char* pointers
 * This Sample code is used to give an example of how to compare strings using two different methods: String::equals() and strcmp()
 * Check the program execution time, storage usage and use of dynamic memory.
 * The second versionn using char* is more efficient but more dangerous to use - mind what you do.
 */

//#define _TEST_1
#if !defined(_TEST_1)
#define _TEST_2
#endif  // !_TEST_1

#if defined(_TEST_1)
void setup() {
  // Initialise the serial port
  Serial.begin(115200);
}

void loop() {
  // String comparison test
  // Create two strings using the String class
  String string1;
  String string2;

  Serial.println("Enter the first string");

  // Wait for the first string
  while(!Serial.available());
  string1 = Serial.readString();
  
  // Print it to check that we got it right
  Serial.println(string1);

  Serial.println("Enter the second string");

  // Wait for the second string
  while(!Serial.available());
  string2 = Serial.readString();

  // Print it to check that we got it right
  Serial.println(string2);

  // Compare the strings
  Serial.print("equals() resulted in ");
  Serial.println(string2.equals(string1));
}
#elif defined(_TEST_2)
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
  Serial.print("strcmp() returned: ");
  Serial.println(strcmp(string1, string2));
  Serial.print("result = ");
  Serial.println(num == strcmp(string1, string2));
  
  delete(string1);
  delete(string2);
}
#endif  // _TEST_1 | _TEST_2
