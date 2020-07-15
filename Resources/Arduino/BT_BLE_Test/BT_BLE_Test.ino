#define SOFT_SERIAL
#define _HM_10

const int LED = 13;
const int LED_ext = A0;

#ifdef SOFT_SERIAL
#include <SoftwareSerial.h>
// insert arrows
const int BTRX = 10;
const int BTTX = 11;
SoftwareSerial ble_device(BTRX, BTTX);
#else
HardwareSerial ble_device = Serial1;
#endif

// Sending the message
String msg;
String str_ii = "";
int ii_0 = 0;

// Setup the connection with Bluetooth Module
void setup()
{
  Serial.begin(115200);
  delay(100);
  Serial.println ("Setup");

  
  ble_device.begin(9600);
  delay(100);

#if defined(_HC_05)
//  ble_help();
//  delay(100);
#endif

  // Enter AT+ commands of interest here (BLE Address, UUIDs, Power settings)
  // NOTE: This is different between HC-05, BT-05, HM-10, etc.
  ble_cmd("AT","Connection check: "); // Connection check - returns OK if all good
#if defined(_HC_05)
  ble_cmd("AT+NAMEBLExAR","Device Name: "); // printout device name
  ble_cmd("AT+LADDR","Address: ");          // printout BLE address
  ble_cmd("AT+CHAR","Char UUID: ");         // printout character UUID
  ble_cmd("AT+VERSION","Version: ");        // module version  
//  ble_cmd("AT+RESET","");                   // reset BLE module
#elif defined(_HM_10)
  ble_cmd("AT+BAUD?","BAUD rate: ");    // printout BAUD rate
  ble_cmd("AT+NAME?","Device Name: ");  // printout device name
  ble_cmd("AT+ROLE?","Device Role: ");  // printout device role
  ble_cmd("AT+ADDR?","Address: ");      // printout BLE address
  ble_cmd("AT+CHAR?","Char UUID: ");    // printout character UUID
  ble_cmd("AT+PASS?","Pass code: ");    // printout PIN code for pairing
  ble_cmd("AT+IMME?","Work mode: ");    // printout Work mode
#endif
  
//  ble_device.println("Bluetooth connection is on");
  pinMode(LED, OUTPUT);
  Serial.println ("Ready to connect");
}

void loop()
{
  if (ble_device.available())
  {
    Serial.write(ble_device.read());
  }
  if (Serial.available())
  {
    ble_device.write(Serial.read());
  }
}

String ble_cmd(String cmd_str,String desc_str){
  str_ii = "";
  unsigned long t1 = millis();
  ble_device.println(cmd_str);
  delay(100);
  
  while (true){
    char in_char = ble_device.read();
    if (int(in_char)==-1 or int(in_char)==42){
      if ((millis()-t1)>2000){ // 2 second timeout
        return "Err";
      }
      continue;
    }
    if (in_char=='\n'){
      Serial.print("Bluetooth "+desc_str);
      Serial.println(str_ii.substring(0,str_ii.length()));
      return str_ii;
    }
    str_ii+=in_char;
  }
}

void ble_help(){
#if defined(_HC_05)
  ble_device.println("AT+HELP");    // list all AT+ commands
#elif defined(_HM_10)
  ble_device.println("AT+HELP?");   // list all AT+ commands | NOTE this command doesn't work 9must change implementation)
#endif
  delay(100);

  while (true){ // loop to print all AT+ commands
    char in_char = ble_device.read();
    if (int(in_char)==-1 or int(in_char)==42){continue;}
    str_ii+=in_char;
    if (in_char=='\n'){
      if (str_ii==String('\r')+String('\n')){
        if (ii_0 == 0){
          ii_0 = 1;
          continue;
        }
        break; // break after more than 1 empty carriage return and newline
      }
      Serial.print(str_ii);
      str_ii = "";
    }
  }
}
