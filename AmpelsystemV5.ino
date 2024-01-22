#include "arduino_config.h"
#include <Servo.h>
Servo barriere;

void setup()
{
pinMode(ROT, OUTPUT); // Pin5 ist ein Ausgang. 
pinMode(GELB, OUTPUT); //Pin6 ist  ein Ausgang.
pinMode(GRUN, OUTPUT); // Pin3 ist ein Ausgang.
pinMode(RotZug, OUTPUT); // Pin8 ist ein Ausgang.
pinMode(GruenZug, OUTPUT); // Pin9 ist ein Ausgang.
barriere.attach(4);
pinMode(magnet1, INPUT); // Pin7 ist ein Eingang.
pinMode(magnet2, INPUT); // Pin11 ist ein Eingang.
attachInterrupt(2, magnet2, RISING);
}

void loop () // Das Hauptprogramm beginnt. 
{
Serial.begin (9600); // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.

digitalWrite(GRUN, HIGH); // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH); // Schaltet die rote Zugampel an Pin8 an.
barriere.write(140);

Serial.print("Magneteins_Zustand:      ");
if(digitalRead(magnet1) == HIGH)
  {
    Serial.print(1);
    delay(2000); // Warte 2s da es bei einer echten Ampel aus Sicherheitsgründen auch immer eine Weile dauert, bis die Ampel umspringt
    digitalWrite(GRUN, LOW);
    digitalWrite(GELB, HIGH);
    delay(2000);
    digitalWrite(GELB, LOW);
    digitalWrite(ROT, HIGH); // Die Autofahrer haben jetzt rot.
    delay(2000);
    barriere.write(40);
    delay(1000);
    digitalWrite(RotZug, LOW);
    digitalWrite(GruenZug, HIGH); 
    delay(20000);
 }
  
}



  

