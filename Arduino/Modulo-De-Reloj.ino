#include <Wire.h>
#include "RTClib.h"

//Se declara el reloj
RTC_DS3231 rtc;

void setup () {
  //Inicia comunicacion
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  //Verifica que el modulo este conectado
  if (!rtc.begin()) {
    Serial.println("El modulo de reloj no esta conectado");
    //Detecta los pins scl y sda del arduino verifica
    //que se este enviando datos al modulo y si es asi
    //signficada que esta conectado el modulo
  }

}

void loop () {
  //Imprimir fecha y hora
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
  delay(1000);
}
