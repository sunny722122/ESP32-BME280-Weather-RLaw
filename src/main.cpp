// This is the master version of this project
<<<<<<< HEAD
=======
// This is another test of gits pull
// this is robbins change
>>>>>>> 68bdcb933f3d7bf8d3e3b748f0c79047a29b1d52
#include <Arduino.h>
#include "sensor_readings.h"
#include "TFT_eSPI.h"     // ESP32 Hardware-specific library
#include "settings.h"    // The order is important!

// bme is global to this file only
Adafruit_BME280 bme;
<<<<<<< HEAD
=======
// tft is global to this file only
>>>>>>> refs/remotes/origin/b3_tft_setup
TFT_eSPI tft = TFT_eSPI();

uint16_t bg = TFT_BLACK;
uint16_t fg = TFT_WHITE;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  bool status;
  // Setup the TFT
<<<<<<< HEAD
  
  tft.begin();

  tft.setRotation(3);
  tft.setTextColor(fg, bg);
  
  tft.fillScreen(bg);
  
=======
  tft.begin();
  tft.setRotation(3);
  tft.setTextColor(fg, bg);
  tft.fillScreen(bg);
>>>>>>> refs/remotes/origin/b3_tft_setup
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
  tft.setCursor(50, 50);
<<<<<<< HEAD
  
  tft.println(millis());
  // passing the bme object by value
  // refresh_readings(bme);
  // Passing the bme object by reference (a pointer: & means pass the address stored in the tft variable).
=======
  tft.println(millis());
  // passing the bme object by value
  // refresh_readings(bme);
  // Passing the bme and tft objects by reference
  //(a pointer: & means pass the address stored in the bme and tft variables).
>>>>>>> refs/remotes/origin/b3_tft_setup
  refresh_readings(&bme, &tft);  
  delay(2000);
}