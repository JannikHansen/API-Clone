#include "setup_Timer.h"
#include "setup_Rain.h"

PT2D rain; 

void setup()
{
  Serial.begin(9600);
  rain.init();
  
}
 
void loop(){

    bool Rfid_Test =1;                                            //-------------------
    if (Rfid_Test == false)                                       //Dieser Bereich muss auf RFID angpasst werden
      {                                                           //und besteht aktuell in dieser Form
        Serial.println("hier könnte eine Fehlermeldung stehen");  //nur zu manuellen Testzwecken
        delay (1000);
      }                                                           //-------------------
    else {
      //A U S F Ü H R U N G  D E R   A N W E N D U N G E N
      time = millis()/1000;                                       // gebe Zeit in sek wieder für bessere Sichtbarkeit

      //Ausführen von Funktion 1
      if (millis() - previousMillis_1 > interval_1) {
        previousMillis_1 = millis();                              // aktuelle Zeit abspeichern
        testausgabe (time, 1);
        int rain_value = rain.getRainValue();                     //Regensensorwert einlesen
        rain.checkRain (rain_value, rainmax);                     //Sensorwert verarbeiten / Beregnung bedienen
        }
      //Ausführen von Funktion 2
      if (millis() - previousMillis_2 > interval_2) {             // Hier könnte eine andere Anwendung ausgeführt werden
        previousMillis_2 = millis();                              // Die Loopzeit für diese kann unter setup_Timer eingestellt werden
        testausgabe (time, 2);
        }
    }
}

