#include "Bewegungsmelder.h"
#include "RFID.h"                                              // Einbinden der Header-Dateien
#include "RolloLicht.h"
#include "setup_Rain.h"
#include "setup_Timer.h"
#include "Temperatursensor.h"


RFID detection;                                                // Objektinstanziierungen für RFIDFunktionen
PT2D rain;                                                     // Objekt Rain für Beregnungsfunktionen.
motionsensor motion;                                           // Objekt für Motion-funktionen 
temperatursensor temp;

void setup()
{
  Serial.begin(9600);                                          
  detection.initRFID();                                        // Setup der einzelnen Teilfunktionen
  rain.init();
  motion.initMotion();
  RolloLicht.leseWunschLicht();
  temp.leseWunschTemp();
  temp.tempAnpassen();
}
 
void loop(){
  
// DIESER LOOP WIRD AUSGEFÜHRT, WENN NOCH KEINE KARTE ERKANNT WURDE

  if (detected==false){                                       // wenn detected=false.. 
    detection.start();                                        // ..Start der RFID-Erkennung.. 
    detection.readCode();                                     // ..Einlesen des Codes..
    detected=detection.checkIdentity();                       // ..und setzen der Variable "detected" auf false, wenn Karte nicht berechtigt bzw. true, wenn Karte berechtigt
  }                                                           

// DIESER LOOP WIRD AUSGEFÜHRT, WENN EINE AUTHORISIERTE KARTE ERKANNT WURDE

  else if (detected) {
      //A U S F Ü H R U N G  D E R   A N W E N D U N G E N
      time = millis()/1000;                                       // gebe Zeit in sek wieder für bessere Sichtbarkeit

     //Ausführen von Funktion 1 (B E R E G N U N G)
      if (millis() - previousMillis_1 > interval_1) {
        previousMillis_1 = millis();                              // aktuelle Zeit abspeichern
        testausgabe (time, 1);
        int rain_value = rain.getRainValue();                     // Regensensorwert einlesen
        rain.checkRain (rain_value, rainmax);                     // Sensorwert verarbeiten / Beregnung bedienen
        }
      //Ausführen von Funktion 2
      if (millis() - previousMillis_2 > interval_2) {             // Hier könnte eine andere Anwendung ausgeführt werden
        previousMillis_2 = millis();                              // Die Loopzeit für diese kann unter setup_Timer eingestellt werden
        testausgabe (time, 2);
        motion.runMotion();
        }
    }
}                                                                 // Ende des Loops




  
  
