#include "arduino_config.h"

void setup()
{
pinMode(ROT, OUTPUT); // Pin5 ist ein Ausgang. 
pinMode(GELB, OUTPUT); //Pin6 ist  ein Ausgang.
pinMode(GRUN, OUTPUT); // Pin7 ist ein Ausgang.
pinMode(RotZug, OUTPUT); // Pin8 ist ein Ausgang.
pinMode(GruenZug, OUTPUT); // Pin9 ist ein Ausgang.
pinMode(trigger, OUTPUT); // Pin3 ist ein Ausgang.
void loop () // Das Hauptprogramm beginnt. 
{
Serial.begin (9600); // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.

digitalWrite(GRUN, HIGH); // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH); // Schaltet die rote Zugampel an Pin8 an.


digitalWrite(trigger, HIGH); // Jetzt sendet man ein Ultraschallwelle los.

dauer = pulseIn(echo, HIGH); // Mit diesem Befehl "pulseIN" zählt der Mikrocontroller die Zeit in Mikrosekunden, bis der Schall zum Ultraschallsensor zurückkehrt.
entfernung = (dauer/2) * 0.03432; 
/* Nun berechnet man die Entfernung in Zentimetern. Man teilt zunächst die Zeit durch 2 (weil man ja nur eine Strecke berechnen möchte.) 
Dem Wert multipliziert man mit der Schallgeschwindigkeit in der Einheit Zentimeter/Mikrosekunde und erhält dann den Wert in Zentimeter.*/

Serial.print("entfernung: ");
Serial.print(entfernung);
Serial.println(" cm");
delay(500);

if (entfernung <= 10 ) 
{
delay(2000); // Warte 2s da es bei einer echten Ampel aus Sicherheitsgründen auch immer eine Weile dauert, bis die Ampel umspringt.
digitalWrite(GRUN, LOW);
digitalWrite(GELB, HIGH);
delay(2000);
digitalWrite(GELB, LOW);
digitalWrite(ROT, HIGH); // Die Autofahrer haben jetzt rot.
delay(2000);
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
}
} // Programmabschnitt des IF-Befehls schliessen.
