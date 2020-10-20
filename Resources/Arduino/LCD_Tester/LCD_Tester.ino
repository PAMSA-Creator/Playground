#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/* 
 *  Connect SDA pin to the Arduino SDA pin
 *  Connect SCL pin to the Arduino SCL pin
 */


void setup()
{
  lcd.init();     // initialize the lcd 

  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hi Vannessa");
  lcd.setCursor(1,1);
  lcd.print("Konichiwaa");
}


void loop()
{

}
