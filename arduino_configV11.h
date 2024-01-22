/*
    /////////////////////////////////////////////////////////////
   //                                                         //
  //                    config-File                          //
 //                                                         //
/////////////////////////////////////////////////////////////
 */

/*================================================================================
Descprition: Stammdaten
Author     : I.Bartsch
Date       : 19.01.2024
Version    : V11.00.00 (Endgültige Version:) )

================================================================================*/

int pieps=2;           // Lautsprecher an Pin 2
int Magnet1=3;         // Reed Kontakt an Pin 3
int Magnet2=11;        // Reed Kontakt an Pin 11
int Magnet3=12;        // Reed Kontakt an Pin 12
int magnetstatus1=0;   // Das Wort "magnetstatus" steht jetzt zunächst für den Wert 0. Später wird   
int magnetstatus2=0;   // unter dieser Variable gespeichert, ob der Reed Kontakt geschlossen ist 
int magnetstatus3=0;   // oder nicht.
int ROT=5;             // Rote LED an Pin 5
int GELB=6;            // Gelbe LED an Pin 5
int GRUN=7;            // Grüne LED an Pin 5
int RotZug=8;          // Rote LED an Pin 5
int GruenZug=9;        // Grüne LED an Pin 5
int phase=0;           // Erste Phase definiert