#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/* 
 *  Connect SDA pin to the Arduino SDA pin
 *  Connect SCL pin to the Arduino SCL pin
 */


// Setup for DHT11
#define DHTPIN  7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  lcd.init();     // initialize the lcd 

  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Hi Vannessa");
  lcd.setCursor(1,1);
  lcd.print("Konichiwaa");

  dht.begin();    // Initialise the sensor
}


void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Check if reads failed
  if(isnan(humidity) || isnan(temperature)){
    lcd.setCursor(0,0);
    lcd.print("! READ FAILED !");
    lcd.setCursor(0,1);
    lcd.print("                ");
  }
  else{ // Print results
    lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Temp.: "); // Prints string "Temp." on the LCD
    lcd.print(temperature); // Prints the temperature value from the sensor
    lcd.print(" C  ");
    lcd.setCursor(0,1);
    lcd.print("Humi.: ");
    lcd.print(humidity);
    lcd.print(" %  ");
    }
  // Wait 2 s before reading again
  delay(2000);
}
