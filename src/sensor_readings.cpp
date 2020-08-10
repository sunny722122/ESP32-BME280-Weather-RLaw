#include <Arduino.h>
#include "sensor_readings.h"
//#include "settings.h"

// Passing the bme and tft objects by reference
// the * means that the parameter called bme will contain an address to the object of type Adafruit_BME280
// For those students using the MCU-6050 this code inside "refresh_readings" 
// will be completely different than for the Adafruit_BME280.
void refresh_readings_bme280(Adafruit_BME280* bme, TFT_eSPI* tft) {
  float f_temperature;
  float f_humidity;
  float f_pressure;
  float f_altitude;

  // If you set this, the TFT will not work!!!
  //digitalWrite(LED_BUILTIN, HIGH); 

  uint16_t bg = TFT_BLACK;
  uint16_t fg = TFT_WHITE;

  // the -> symbol means to de-reference the pointer.
  tft->setCursor(5, 5);
  tft->setTextColor(fg, bg);
  // Create TTF fonts using instructions at https://pages.uoregon.edu/park/Processing/process5.html
  tft->loadFont("SansSerif-36");
  tft->println("Right now...");

  f_temperature = bme->readTemperature();
  f_humidity    = bme->readHumidity();
  f_pressure    = bme->readPressure() / 100.0F;
  f_altitude    = bme->readAltitude(SEALEVELPRESSURE_HPA);

  tft->setTextColor(TFT_YELLOW, bg);

  // Temperature
  Serial.print(f_temperature);
  Serial.println(" °C");
  tft->fillRect(5, 50, 140, 30, bg);
  tft->setCursor(5, 50);
  tft->print(f_temperature);
  tft->println(" °C");

  // Humidity
  Serial.print(f_humidity);
  Serial.println(" %");
  tft->fillRect(5, 90, 130, 30, bg);
  tft->setCursor(5, 90);
  tft->print(f_humidity);
  tft->println(" %");

  // Pressure 
  Serial.print(f_pressure);
  Serial.println(" hPa");
  tft->fillRect(5, 130, 200, 30, bg);
  tft->setCursor(5, 130);
  tft->print(f_pressure);
  tft->println(" hPa");

  // Appx altitude
  Serial.print(f_altitude);
  Serial.println(" m");   
  tft->fillRect(5, 170, 200, 30, bg);
  tft->setCursor(5, 170);
  tft->print(f_altitude); 
  tft->println(" m");
  
  //digitalWrite(LED_BUILTIN, LOW);
  Serial.println("-----v3----");   
}

void refresh_readings_mpu6050(TFT_eSPI* tft){

}