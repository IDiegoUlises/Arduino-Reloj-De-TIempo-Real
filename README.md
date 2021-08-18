# Arduino-Reloj-De-Tiempo-Real

Primero como obtiene la fecha en tiempo real??? sin ser configurado 

codigo 

```c++
//Paso 1
#include <Wire.h>
#include "RTClib.h"

//Paso 2
RTC_DS3231 rtc;

void setup () {
  //Paso 3
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  //Paso 4
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  //Paso 5
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //rtc.adjust(DateTime(2015, 1, 1, 3, 0, 0));
  }
}

void loop () {
  //Paso 6
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  Serial.println();
  delay(3000);
}

```
