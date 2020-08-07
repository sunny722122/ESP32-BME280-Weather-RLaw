#include <Arduino.h>

/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME    "futureshocked"
#define IO_KEY         "c10ce8eff2ad45c499dd864629ae40e2"

/******************************* WIFI **************************************/
#define WIFI_SSID       "ardwifi"
#define WIFI_PASS       "ardwifi987"

#include "AdafruitIO_WiFi.h"   // Beware, at the time of writting this, the Adafruit library needs platform-espressif32 version 1.7.0, https://github.com/platformio/platform-espressif32/releases, specified in platform.io
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
