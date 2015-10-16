/*
 * main.cpp
 *
 *  Created on: 16/6/2015
 *      Author: Carlos Villar
 *  Última modificación: 16/10/2015
 *  Programa para compilar dentro del entorno
 *  eclipse
 */

#include <Arduino.h>

// defino el pin que se usa para el led
int led = 13;

void setup () {
  //Defino el pin como salida
   pinMode(led, OUTPUT);
   //Inicializo el puerto serie 1 a 9600 baudios
   Serial.begin(9600);

   // retorno de carro + nueva línea \r\n
   // para visualizarlo bien en las terminales
   Serial.write("OiT 1\n\rInicio el programa\r\n");
   Serial.write("Para Encender el LED pulse E\r\n");
   Serial.write("Para apagarlo pulse A\r\n");
}

void loop () {
  //Si está disponible algún dato en el puerto serie
   if (Serial.available()) {
     //Guardamos la lectura en una variable char
      char c = Serial.read();

      //Si es una 'E' o 'e', enciendo el LED
      if (c == 'E' || c == 'e') {
         digitalWrite(led, HIGH);
         Serial.write("Enciendo el led\n\r");

     //Si es una 'A' o 'a', apago el LED
   } else if (c == 'A' || c == 'a') {
         digitalWrite(led, LOW);
         Serial.write("Apago el led\n\r");
      }
   }
}

int main(void) {

  init();
  setup();

  while(true) {
    loop();
  }
}
