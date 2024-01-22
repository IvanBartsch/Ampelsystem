#include "arduino_config.h"
#include <Servo.h>
Servo barriere;

void setup()
{
pinMode(ROT, OUTPUT); // Pin5 ist ein Ausgang. 
pinMode(GELB, OUTPUT); //Pin6 ist  ein Ausgang.
pinMode(GRUN, OUTPUT); // Pin7 ist ein Ausgang.
pinMode(RotZug, OUTPUT); // Pin8 ist ein Ausgang.
pinMode(GruenZug, OUTPUT); // Pin9 ist ein Ausgang.
barriere.attach(4);
pinMode(Taster, INPUT); // Pin11 ist ein Eingang.
}
void loop () // Das Hauptprogramm beginnt. 
{
Serial.begin (9600); // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.
Serial.print("Reed Switch Sensor - ");


digitalWrite(GRUN, HIGH); // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH); // Schaltet die rote Zugampel an Pin8 an.
barriere.write(140);
tasterstatus=digitalRead(Taster); // Hier wird der Pin4 ausgelesen (Befehl:digitalRead)


if (tasterstatus == HIGH) 
{
delay(2000); // Warte 2s da es bei einer echten Ampel aus Sicherheitsgründen auch immer eine Weile dauert, bis die Ampel umspringt.
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
delay(10000);
digitalWrite(RotZug, HIGH);
digitalWrite(GruenZug, LOW);
delay(2000);
digitalWrite(ROT, LOW);
digitalWrite(GELB, HIGH);
delay(2000);
digitalWrite(GELB, LOW);
digitalWrite(GRUN, HIGH);
barriere.write(140);
}
else
 {
    Serial.print(0);
 }


} // Programmabschnitt des IF-Befehls schliessen.
