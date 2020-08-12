#include <Arduino.h>

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  "sunny722"
#define IO_KEY       "aio_WDQa51np7QGePmhtATqxVoEXJ4CI"

// wifi credentials
#define WIFI_SSID       "TELUS1005"
#define WIFI_PASS       "nfnb33pgv2"

#include "AdafruitIO_WiFi.h"   
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
