#include <Arduino.h>
#include "sensor_readings.h"
#include "TFT_eSPI.h"     // ESP32 Hardware-specific library
#include "settings.h"    // The order is important!

#define LED_ONBOARD_PIN 2

// bme is global to this file only
Adafruit_BME280 bme;
// tft is global to this file only
TFT_eSPI tft = TFT_eSPI();

uint16_t bg = TFT_BLACK;
uint16_t fg = TFT_WHITE;

// LED
struct Led
{
    uint8_t pin;
    bool on;

    void update()
    {
        digitalWrite(pin, on ? HIGH : LOW);
    }
};

// Global Variables
Led onboard_led = {LED_ONBOARD_PIN, false};

void initSPIFFS()
{
    if (!SPIFFS.begin())
    {
        Serial.println("Cannot mount SPIFFS volume...");
        while (1){}
    }
    else
    {
        Serial.println("SPIFFS volume mounted properly");
    }
}

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  initSPIFFS();
  bool status;
  // Setup the TFT
  tft.begin();
  tft.setRotation(3);
  //tft.loadFont("SansSerif-36");
  tft.loadFont("NotoSansBold20");
  tft.setTextColor(fg, bg);
  tft.fillScreen(bg);
  tft.setCursor(0, 0);
  tft.println("Hello!");
  tft.println("Starting BME sensor...");
  delay(5000);

  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);  // Infinite loop
  }
  tft.fillScreen(bg);
}

void loop() {
  // Passing the bme object by value
  // refresh_readings_bme280(bme);
  // Passing the bme and tft objects by reference
  // (a pointer: & means pass the address stored in the bme and tft variables).
  refresh_readings_bme280(&bme, &tft);

  // For those students who are using the MPU-6050, 
  // this call to "refresh_readings" will be slightly different.
  //refresh_readings_mpu6050(&tft);
  delay(2000);
}