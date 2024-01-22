#include "arduino_config.h"
#include <Servo.h>                            // Servo Bibliothek wird eingebunden.
Servo barriere;                               // Erstellt für das Programm ein Servo mit dem Namen "barriere".
#include <Wire.h>                             // Wire Bibliothek wird eingebunden.
#include <LiquidCrystal_I2C.h>                // LiquidCrystal_I2C Bibliothek wird eingebunden.
LiquidCrystal_I2C lcd(0x27, 16, 2);           /* Hier wird festgelegt, um was für einen Display es sich handelt.
                                              In diesem Fall eines mit 16 Zeichen in 2 Zeilen und der Hex-Adresse0x27.
                                              */
void setup()                                  // Hier beginnt das Setup.
{                                             // Programmabschnitt beginnt. 
pinMode(Magnet1, INPUT);                      // Pin 3 ist ein Eingang.
pinMode(Magnet2, INPUT);                      // Pin 11 ist ein Eingang.
pinMode(Magnet3, INPUT);                      // Pin 12 ist ein Eingang.  
barriere.attach(4);                           // Servo wird mit Pin 4 verbunden.
pinMode(pieps, OUTPUT);                       // Pin 2 ist ein Ausgang.
pinMode(ROT, OUTPUT);                         // Pin 5 ist ein Ausgang. 
pinMode(GELB, OUTPUT);                        // Pin 6 ist  ein Ausgang.
pinMode(GRUN, OUTPUT);                        // Pin 7 ist ein Ausgang.
pinMode(RotZug, OUTPUT);                      // Pin 8 ist ein Ausgang.
pinMode(GruenZug, OUTPUT);                    // Pin 9 ist ein Ausgang.
lcd.init();                                   // Im Setup wird der LCD gestartet. 
lcd.backlight();                              // Hintergrundbeleuchtung einschalten.
Serial.begin (9600);                          // Serielle Kommunikation startet, damit man sich später die Werte am Seriellen Monitor anschauen kann.
digitalWrite(GRUN, HIGH);                     // Schaltet die grüne LED an PIN7 an. Die Autos sehen also das grüne Signal.
digitalWrite(RotZug, HIGH);                   // Schaltet die rote Zugampel an Pin8 an.
barriere.write(10);                           // Barriere offen.

}                                             // Programmabschnitt beendet.
void loop () {                                // Das Hauptprogramm beginnt. 

  lcd.setCursor(0, 0);                        // Hier wird die Position der ersten Zeichens festgelegt. In diesem Fall bedeutet (0,0) das erste Zeichen in der ersten Zeile.
  lcd.print("Mein Ampelsystem");              // In der ersten Zeile erschein der Text "Mein Ampelsystem".
  lcd.setCursor(0, 1);                        // In diesem Fall bedeutet (0,1) das erste Zeichen in der zweiten Zeile.
  lcd.print("Viel Spass!");                   // In der zweiten Zeile erscheint der Text "Viel Erfolg".

  magnetstatus1=digitalRead(Magnet1);         // Hier wird der Pin3,11 und 12 ausgelesen (Befehl:digitalRead).
  magnetstatus2=digitalRead(Magnet2);         // Das Ergesbnis wird unter der Variable "tasterstatus" mit dem Wert "HIGH" für 5 Volt oder "LOW" für 0 Volt gespeichert.
  magnetstatus3=digitalRead(Magnet3);         
  
  Serial.print("Magnet Zustandeins: ");       // Im Fall das der ausgelesen Pin den Wert "HIGH" ausliest, dann erscheint im Seriellen Monitor Magnet Zustandein 1 
  if (digitalRead(Magnet1) == HIGH) {         // und falls er den Wert "LOW" ausliest dann erscheint im Seriellen Monitor Magnet Zustandein 0.
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println();                           // Füge einen Zeilenumbruch hinzu.
  delay(10);                                  // Warte 10 milli Sekunden.
                                              // Von Zeile 40-47 wiederholt sich jetzt alles (für Magnet2 & Magnet3) bis und mit Zeile 65.
  Serial.print("Magnet Zustandzwei: ");
  if (digitalRead(Magnet2) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); 
  delay(10); 

  Serial.print("Magnet Zustanddrei: ");
  if (digitalRead(Magnet3) == HIGH) {
    Serial.print(1);
  } else {
    Serial.print(0);
  }
  Serial.println(); 
  delay(10); 

  if (phase == 0 && magnetstatus1 == HIGH) {  /* Hier muss die erste Phase beginnen & der erste Reed Kontakt muss geschlossen sein,
                                              damit der folgende Programmblock verarbeitet wird.*/
  digitalWrite(GRUN, LOW);                    // Die grüne Ampel für die Autos erliescht. 
  digitalWrite(GELB, HIGH);                   // Die gelbe Ampel für die Autos beginnt zu leuchten.
  digitalWrite(pieps, HIGH);                  // Der Lautsprcher gibt eine Warnton raus.
  delay(600);                                 // Warte 600 milli Sekunden.
  digitalWrite(pieps, LOW);                   // Der Lautsprcher wird wieder leise.
  digitalWrite(GELB, LOW);                    // Die gelbe Ampel für die Autos erliescht. 
  digitalWrite(ROT, HIGH);                    // Die rote Ampel für die Autos beginnt zu leuchten.
  delay(600);                                 // Warte 600 milli Sekunden.
  barriere.write(100);                        // Die Barriere wird geschlossen.
  phase=1;                                    // Wechsle zur nächsten Phase
  }                                           // Programmabschnitt des IF-Befehls schliessen.

  if (phase == 1 && magnetstatus2 == HIGH) {  /* Hier muss die erste Phase bereits abgeschlossen sein & der zweite Reed Kontakt muss geschlossen sein,
                                              damit der folgende Programmblock verarbeitet wird.*/
  digitalWrite(RotZug, LOW);                  // Die rote Ampel des Zuges erliescht.
  digitalWrite(GruenZug, HIGH);               // Die grüne Ampel des Zuges beginnt zu leuchten.
  phase=2;                                    // Wechsle zur nächsten Phase
  }                                           // Programmabschnitt des IF-Befehls schliessen.

  if (phase == 2 && magnetstatus3 == HIGH) {  /* Hier muss die zweite Phase bereits abgeschlossen sein & der dritte Reed Kontakt muss geschlossen sein,
                                              damit der folgende Programmblock verarbeitet wird.*/
  digitalWrite(RotZug, HIGH);                 // Die rote Ampel des Zuges beginnt zu leuchten.
  digitalWrite(GruenZug, LOW);                // Die grüne Ampel des Zuges erliescht.
  digitalWrite(ROT, LOW);                     // Die rote Ampel für die Autos erliescht. 
  delay(1000);                                // Warte 1 Sekunde.
  digitalWrite(GELB, HIGH);                   // Die rote Ampel für die Autos beginnt zu leuchten.
  digitalWrite(GELB, LOW);                    // Die gelbe Ampel für die Autos erliescht. 
  barriere.write(10);                         // Die Barriere öffnet sich.
  digitalWrite(GRUN, HIGH);                   // Die grüne Ampel für die Autos beginnt zu leuchten.
  phase=0;                                    // Zurücksetzen auf Phase 0 
  }                                           // Programmabschnitt des IF-Befehls schliessen.
}                                             // Hier am Ende springt das Programm an den Start des Loop-Teils. 


 