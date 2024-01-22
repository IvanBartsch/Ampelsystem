#include "arduino_config.h"
#include <Servo.h>
Servo barriere;

void setup()
{
pinMode(pieps, OUTPUT); // Pin2 ist ein Ausgang.
pinMode(Magnet, INPUT); // Pin3 ist ein Eingang.   
barriere.attach(4);
pinMode(ROT, OUTPUT); // Pin5 ist ein Ausgang. 
pinMode(GELB, OUTPUT); //Pin6 ist  ein Ausgang.
pinMode(GRUN, OUTPUT); // Pin7 ist ein Ausgang.
pinMode(RotZug, OUTPUT); // Pin8 ist ein Ausgang.
pinMode(GruenZug, OUTPUT); // Pin9 ist ein Ausgang.
}
void loop () // Das Hauptprogramm beginnt. 
{
Serial.begin (9600); // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.

digitalWrite(GRUN, HIGH); // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH); // Schaltet die rote Zugampel an Pin8 an.
barriere.write(10);
magnetstatus=digitalRead(Magnet); // Hier wird der Pin3 ausgelesen (Befehl:digitalRead)
// Das Ergesbnis wird unter der Variable "tasterstatus" mit dem Wert "HIGH" für 5 Volt oder "LOW" für 0 Volt gespeichert.
if (magnetstatus == HIGH) {
delay(2000);
digitalWrite(GRUN, LOW);
digitalWrite(GELB, HIGH);
digitalWrite(pieps, HIGH);
delay(1000);
digitalWrite(pieps, LOW);
digitalWrite(GELB, LOW);
digitalWrite(ROT, HIGH);
barriere.write(100);
delay(2000);
digitalWrite(RotZug, LOW);
digitalWrite(GruenZug, HIGH);
delay(5000);
digitalWrite(RotZug, HIGH);
digitalWrite(GruenZug, LOW);
delay(2000);
digitalWrite(GELB, HIGH);
delay(1000);
digitalWrite(ROT, LOW);
digitalWrite(GELB, LOW);
} // Programmabschnitt des IF-Befehls schliessen.
}

