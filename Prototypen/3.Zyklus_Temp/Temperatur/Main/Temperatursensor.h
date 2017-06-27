#define TempPort A0

// KLASSENDEFINITION
// Klasse für den Temperatursteuerung, die die entsprechenden Methoden beinhaltet
class tempsensor {
  public:
    void init();
   
    int getTempValue();
    void tempAnpassen();
    int leseWunschTemp();
    bool getTasterstatus();
    int taster = 12;
    int wunschtemp;
};

// METHODENDEFINITION
// Initiallierung des Boards und Zuweisung der Ports
  void tempsensor::init(){
    
  // Beginnt die Übertragung an den seriellen Monitor
  Serial.begin(9600);
  
  pinMode(TempPort,INPUT);

  pinMode(13, OUTPUT);			// Pin 13 und 11 als Output für die LEDs           
  pinMode(11, OUTPUT);			// der Temperatursteuerung

}

/** // Methode zur Rückgabe des Temperaturwertes, für Testfunktion eventuell noch relevant
// JETZT IN ° CELSIUS über map-Befehl
  int arduino::getTempValue(){
  int sensorwert = analogRead(TempPort);
  int messwert = map(sensorwert, 0, 410, -50, 150);
  return messwert;
}
*/

// METHODE zur Überprüfung des Tasterstatus
  bool tempsensor::getTasterstatus(){
  bool tasterstatus = digitalRead(taster);
  return tasterstatus;
  }
  
// METHODE zum Einlesen der Wuschtemperatur
int tempsensor::leseWunschTemp() 
{
  int wunschtemp = 0;
  int i; 
  char X_buffer[4]; 

  Serial.print("Geben Sie Ihre gewünschte Temperatur ein: ");

  if(wunschtemp == 0)
  {
    if (Serial.available())                                           // überprüft, ob Daten an den Arduino gesendet werden (returns true, wenn der serielle Puffer nicht leer ist)
    {
      Serial.flush();                                                 // wartet, bis alle seriellen Daten gesendet wurden
      delay(5); 
      i=0;      
      while(i<5)
      {
        X_buffer[i] = Serial.read();                                  // liest nacheinander vier Zeichen ein und gibt sie als string zurück
        i++; 
      }
      Serial.flush();
      wunschtemp = atoi(X_buffer);                                    // wandelt zu int-Wert um
      Serial.println(wunschtemp);
      return wunschtemp;
    } 
  }
}

/** METHODE für das Anschalten von keiner, einer LED oder zwei LEDs 
 *  (nicht, ein wenig oder stark heizen)
  */
  
void tempsensor::tempAnpassen (){
  int temperatur = 0;
  int sensorwert = analogRead(TempPort);
  temperatur = map(sensorwert, 0, 410, -50, 150);
  
  
if(temperatur <= 10) {                                        // Wenn die Temperatur kleiner als 10° Celsius werden beide LEDs angeschaltet (Heizung voll aufgedreht)
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
}
else if(temperatur > 10 && temperatur <= wunschtemp) {        // Ist die Temperatur zwar höher als 10° Celsius, aber noch unter Wunschtemperatur wird nur eine LED angeschaltet
  digitalWrite(13, HIGH);                                     // (Heizung läuft auf kleinerer Stufe).
  digitalWrite(11, LOW);
}
else if(temperatur > wunschtemp){                             // Ist der Wert größer oder gleich der Wunschtemperatur werden beide LEDs ausgeschaltet
  digitalWrite(13, LOW);                                      // (Heizung aus).
  digitalWrite(11, LOW);
}
}
