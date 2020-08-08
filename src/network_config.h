#include <Arduino.h>

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  "robbinlaw"
#define IO_KEY       "e4356af15f9741bb91e5365c0c89de7e"

// wifi credentials
#define WIFI_SSID       "OldRob"
#define WIFI_PASS       "5223qaz7542PLM"

#include "AdafruitIO_WiFi.h"   
// Beware, at the time of writting this, 
// the Adafruit library needs platform-espressif32 
// version 1.7.0, https://github.com/platformio/platform-espressif32/releases, specified in platform.io
//AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
