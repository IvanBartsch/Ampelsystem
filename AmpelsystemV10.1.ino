#include "arduino_config.h"
#include <Servo.h>
Servo barriere;
#include <Wire.h> // Wire Bibliothek wird eingebunden.
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
pinMode(pieps, OUTPUT); // Pin2 ist ein Ausgang.
pinMode(Magnet1, INPUT); // Pin3 ist ein Eingang.
pinMode(Magnet2, INPUT); // Pin11 ist ein Eingang.
pinMode(Magnet3, INPUT); // Pin12 ist ein Eingang.  
pinMode(Magnet4, INPUT); // Pin13 ist ein Eingang.
pinMode(Magnet5, INPUT); // Pin51 ist ein Eingang.
pinMode(Magnet6, INPUT); // Pin52 ist ein Eingang.  
pinMode(Magnet7, INPUT); // Pin53 ist ein Eingang. 
barriere.attach(4);
pinMode(ROT, OUTPUT); // Pin5 ist ein Ausgang. 
pinMode(GELB, OUTPUT); //Pin6 ist  ein Ausgang.
pinMode(GRUN, OUTPUT); // Pin7 ist ein Ausgang.
pinMode(RotZug, OUTPUT); // Pin8 ist ein Ausgang.
pinMode(GruenZug, OUTPUT); // Pin9 ist ein Ausgang.
lcd.init();
lcd.backlight();
Serial.begin (9600); // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.
digitalWrite(GRUN, HIGH); // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH); // Schaltet die rote Zugampel an Pin8 an.
barriere.write(10); // Barriere offen

}
void loop () {   // Das Hauptprogramm beginnt. 

  lcd.setCursor(0, 0);
  lcd.print("Mein Ampelsystem");
  lcd.setCursor(0, 1);
  lcd.print("Viel Spass!");

  magnetstatus1=digitalRead(Magnet1); // Hier wird der Pin3 ausgelesen (Befehl:digitalRead)
  // Das Ergesbnis wird unter der Variable "tasterstatus" mit dem Wert "HIGH" für 5 Volt oder "LOW" für 0 Volt gespeichert.
  magnetstatus2=digitalRead(Magnet2);
  magnetstatus3=digitalRead(Magnet3);
  magnetstatus4=digitalRead(Magnet4);
  magnetstatus5=digitalRead(Magnet5);
  magnetstatus5=digitalRead(Magnet6);
  magnetstatus6=digitalRead(Magnet7);

  Serial.print("Magnet Zustandeins: ");
  if (digitalRead(Magnet1) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); // Füge einen Zeilenumbruch hinzu
  delay(10); // Warte 2 Sekunden

  Serial.print("Magnet Zustandzwei: ");
  if (digitalRead(Magnet2) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); // Füge einen Zeilenumbruch hinzu
  delay(10); // Warte 2 Sekunden

  Serial.print("Magnet Zustanddrei: ");
  if (digitalRead(Magnet3) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); // Füge einen Zeilenumbruch hinzu
  delay(10); // Warte 2 Sekunden

  Serial.print("Magnet Zustandvier: ");
  if (digitalRead(Magnet4) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); // Füge einen Zeilenumbruch hinzu
  delay(10); // Warte 2 Sekunden

  Serial.print("Magnet Zustandfünf: ");
  if (digitalRead(Magnet5) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); // Füge einen Zeilenumbruch hinzu
  delay(10); // Warte 2 Sekunden

  Serial.print("Magnet Zustandsechs: ");
  if (digitalRead(Magnet6) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); // Füge einen Zeilenumbruch hinzu
  delay(10); // Warte 2 Sekunden

  Serial.print("Magnet Zustandsieben: ");
  if (digitalRead(Magnet7) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); // Füge einen Zeilenumbruch hinzu
  delay(10); // Warte 2 Sekunden



  if (phase == 0 && magnetstatus1 == HIGH) {

  digitalWrite(GRUN, LOW);
  digitalWrite(GELB, HIGH);
  digitalWrite(pieps, HIGH);
  phase=1; //Wechsle zur nächsten Phase
  }
  if (phase == 1 && magnetstatus2 == HIGH) {
  digitalWrite(pieps, LOW);
  digitalWrite(GELB, LOW);
  digitalWrite(ROT, HIGH);
  phase=2; //Wechsle zur nächsten Phase
  }
  if (phase == 2 && magnetstatus3 == HIGH) {
  barriere.write(100); // geschlossen
  phase=3; //Wechsle zur nächsten Phase
  }

  if (phase == 3 && magnetstatus4 == HIGH) {
  digitalWrite(RotZug, LOW);
  digitalWrite(GruenZug, HIGH);
  phase=4; // Wechsle zur nächsten Phase
  }  
  if (phase == 4 && magnetstatus5 == HIGH) {
  digitalWrite(RotZug, HIGH);
  digitalWrite(GruenZug, LOW);
  phase=5; //Wechsle zur nächsten Phase
  }
  if (phase == 5 && magnetstatus6 == HIGH) {
  digitalWrite(GELB, HIGH);
  phase=6; //Wechsle zur nächsten Phase
  }
  if (phase == 6 && magnetstatus7 == HIGH) {
  digitalWrite(GELB, LOW);
  digitalWrite(ROT, HIGH);
  phase=0; // Zurücksetzen auf Phase 0 
  }          
  
} // Programmabschnitt des IF-Befehls schliessen.


 