#include "setup_Rain.h"

PT2D rain;                //Erstellt ein Objekt Rain aus der Klasse für den Prototypen 2D das den Anwendungsbereich Rain übernimmt.
                          // Auf eine Klasse könnte eventuell ganz verzichtet werden.
void setup() {
  rain.init();            //initalisierung von INPUT/OUTPUT Ports für Rain Anwendung
}

void loop() {
  int rain_value = rain.getRainValue();        //Einlesen des Sensorts (muss im loop passieren)
  rain.checkRain (rain_value, rainmax);        //Überprüfen ob Rasen ausreichend Feucht, Rainmax legt Schwellenwert fest
  delay(60*1000*15);                             //Warte (60*1 sek *15)= 15min    (!!Zwecks Sensorschonung!!)

}
