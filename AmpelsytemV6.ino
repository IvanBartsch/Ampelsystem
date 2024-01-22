#include "arduino_config.h"

void setup()
{
pinMode(magnet1, INPUT); // Pin7 ist ein Eingang.
pinMode(magnet2, INPUT); // Pin11 ist ein Eingang.
}

void loop () // Das Hauptprogramm beginnt. 
{
Serial.begin (9600); // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.
Serial.print("Magneteins_Zustand:      ");

if(digitalRead(magnet1) == HIGH)
  {
    Serial.print(1);
 }
  else
 {
    Serial.print(0);
 }
Serial.println("Magneteins_Zustand:      ");

if(digitalRead(magnet2) == HIGH)
  {
    Serial.print(1);
 }
  else
 {
    Serial.print(0);
 }

delay(500);
}
