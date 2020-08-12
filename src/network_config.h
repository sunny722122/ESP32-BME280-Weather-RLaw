#include <Arduino.h>

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  "Adafruit IO username"
#define IO_KEY       "adafruit IO key"

// wifi credentials
#define WIFI_SSID       "your SSID"
#define WIFI_PASS       "your pass"

#include "AdafruitIO_WiFi.h"   
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
