# Arduino-Reloj-De-Tiempo-Real

Primero como obtiene la fecha en tiempo real??? sin ser configurado 

dato este modulo no tiene bateria contiene un super condensador alimenta el circuito que guarda la fecha

## wire
I2C es un protocolo síncrono. I2C usa solo 2 cables, uno para el reloj (SCL) y otro para el dato (SDA). Esto significa que el maestro y el esclavo envían datos por el mismo cable, el cual es controlado por el maestro, que crea la señal de reloj. I2C no utiliza selección de esclavo, sino direccionamiento.

I2C es un bus de comunicaciones en serie. Su nombre viene de Inter-Integrated Circuit (Inter-Circuitos Integrados). La versión 1.0 data del año 1992 y la versión 2.1 del año 2000, su diseñador es Philips. La velocidad es de 100 kbit/s en el modo estándar, aunque también permite velocidades de 3.4 Mbit/s. Es un bus muy usado en la industria, principalmente para comunicar microcontroladores y sus periféricos en sistemas integrados (Embedded Systems) y generalizando más para comunicar circuitos integrados entre si que normalmente residen en un mismo circuito impreso.

La principal característica de I²C es que utiliza dos líneas para transmitir la información: una para los datos y otra para la señal de reloj. También es necesaria una tercera línea, pero esta sólo es la referencia (masa). Como suelen comunicarse circuitos en una misma placa que comparten una misma masa esta tercera línea no suele ser necesaria.

codigo 

```c++
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
    //Detecta los pins scla y sda del arduino verifica
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
```
