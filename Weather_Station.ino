#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>

// Define the DHT sensor pin and object
#define dht_apin A0 
dht DHT;

// Set the LCD I2C address and dimensions (16x2 in this case)
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 is the I2C address, adjust if necessary

void setup() 
{
  // Initialize I2C LCD
  lcd.begin(16,2);
  
  pinMode(2, INPUT); // Pin 2 for an external input (e.g., a button or sensor)
}

void loop() 
{
  // Read temperature and humidity from the DHT sensor
  DHT.read22(dht_apin); // Read DHT22 sensor data

  // Get the temperature value
  int Temp = DHT.temperature;
  lcd.setCursor(0, 0); // Set cursor to the first row
  lcd.print("TEMP: ");
  lcd.print(Temp);
  lcd.print("C  "); // Print Celsius symbol

  // Get the humidity value
  int Humidity = DHT.humidity;
  lcd.setCursor(0, 1); // Set cursor to the second row
  lcd.print("HM: ");
  lcd.print(Humidity);
  lcd.print("%  "); // Print percentage symbol

  delay(2000); // Delay to update readings every 2 seconds
}


