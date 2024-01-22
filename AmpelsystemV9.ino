#include "arduino_config.h"
#include <Servo.h>
Servo barriere;
#include <Wire.h> // Wire Bibliothek wird eingebunden.
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

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
lcd.init();
lcd.backlight();
Serial.begin (9600); // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.
}
void loop () // Das Hauptprogramm beginnt. 
{
lcd.setCursor(0, 0);
lcd.print("Mein Ampelsystem");
lcd.setCursor(0, 1);
lcd.print("Viel Spass!");

digitalWrite(GRUN, HIGH); // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH); // Schaltet die rote Zugampel an Pin8 an.
barriere.write(10); // Barriere offen
magnetstatus=digitalRead(Magnet); // Hier wird der Pin3 ausgelesen (Befehl:digitalRead)
// Das Ergesbnis wird unter der Variable "tasterstatus" mit dem Wert "HIGH" für 5 Volt oder "LOW" für 0 Volt gespeichert.

Serial.print("Magnet Zustand: ");
 if (digitalRead(Magnet) == HIGH) {
   Serial.print(1);
 } else {
   Serial.print(0);
 }
 Serial.println(); // Füge einen Zeilenumbruch hinzu
 delay(1000); // Warte 1 Sekunden


if (magnetstatus == HIGH) {


digitalWrite(GRUN, LOW);
digitalWrite(GELB, HIGH);
digitalWrite(pieps, HIGH);
digitalWrite(RotZug, LOW);
digitalWrite(GruenZug, HIGH);
barriere.write(100);
delay(1500);
digitalWrite(pieps, LOW);
digitalWrite(GELB, LOW);
digitalWrite(ROT, HIGH);
delay(1000);
delay(2000);
digitalWrite(RotZug, HIGH);
digitalWrite(GruenZug, LOW);
delay(1000);
digitalWrite(GELB, HIGH);
delay(500);
digitalWrite(ROT, LOW);
digitalWrite(GELB, LOW);
} // Programmabschnitt des IF-Befehls schliessen.
}








