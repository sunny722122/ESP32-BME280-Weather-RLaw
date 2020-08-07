#ifndef SETTINGS_H
    #define SETTINGS_H
    #define LED_BUILTIN 2   // This is valid for my devkit
#endif

#ifdef DEBUGLOG
#define DEBUGPRINT(x)     Serial.print (x)
#define DEBUGPRINTDEC(x)     Serial.print (x, DEC)
#define DEBUGPRINTLN(x)  Serial.println (x)
#else
#define DEBUGPRINT(x)
#define DEBUGPRINTDEC(x)
#define DEBUGPRINTLN(x)
#endif