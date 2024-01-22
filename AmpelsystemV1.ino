#include "arduino_config.h"

void setup()
{
pinMode(Taster, INPUT); // Pin4 ist ein Eingang.
pinMode(ROT, OUTPUT); // Pin5 ist ein Ausgang. 
pinMode(GELB, OUTPUT); //Pin6 ist  ein Ausgang.
pinMode(GRUN, OUTPUT); // Pin7 ist ein Ausgang.
pinMode(RotZug, OUTPUT); // Pin8 ist ein Ausgang.
pinMode(GruenZug, OUTPUT); // Pin9 ist ein Ausgang.
}
void loop () // Das Hauptprogramm beginnt. 
{
digitalWrite(GRUN, HIGH); // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH); // Schaltet die rote Zugampel an Pin8 an.
tasterstatus=digitalRead(Taster); // Hier wird der Pin4 ausgelesen (Befehl:digitalRead)
// Das Ergesbnis wird unter der Variable "tasterstatus" mit dem Wert "HIGH" für 5 Volt oder "LOW" für 0 Volt gespeichert.
if (tasterstatus == HIGH) {
delay(2000);
digitalWrite(GRUN, LOW);
digitalWrite(GELB, HIGH);
delay(1000);
digitalWrite(GELB, LOW);
digitalWrite(ROT, HIGH);
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