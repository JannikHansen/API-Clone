#define TMP36 A0                                          // Der Sensor soll am analogen Pin A0 angeschlossen werden. Wir nennen den Pin ab jetzt "TMP36"
int sensorwert;
int temperatur = 0;                                       // Unter der Variablen "temperatur" wird später der Temperaturwert abgespeichert.
int t=500;                                                // Der Wert für „t“ gibt im Code die zeitlichen Abstände zwischen den einzelnen Messungen vor.
int wunschtemp;                                       // Unter "wuschtemp" wird später die gewünschte Temperatur abgespeichert.
int taster = 12;                                          // Ein Taster wird am Pin 12 angeschlossen.
int tasterstatus;

/** 
 *  Im Setup beginnt die serielle Kommunikation, damit die Temperatur an den serial monitor übertragen wird. 
 *  Über die serielle Kommunikation sendet das Board die Messwerte an den Computer. 
 *  In der Arduino-Software kann man unter „Werkzeuge“ den „Seriellen Monitor“ starten um die Messwerte zu sehen.
 */
void setup() 
{
  Serial.begin(9600);  
                                                          
  pinMode(13 , OUTPUT);                               
  pinMode(11, OUTPUT);
}

/** 
 * Der Benutzer kann bei Drücken des Tasters seine Wunschtemperatur über den seriellen Monitor eingeben. 
 * Der gewünschte Wert wird in einen char-array der Länge 4 geschrieben und später in einen int-Wert umgewandelt.
 * Die Wunschtemperatur wird im seriellen Monitor angezeigt.
 */
void leseWunschTemp()
{
  int i;
  char X_buffer[4];                                                   //Max. Zahl "9999"
  wunschtemp = 0;
 
  Serial.print("Geben Sie Ihre gewünschte Temperatur ein: ");

  while(wunschtemp == 0)
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
    } 
  }
}

/**
 * Wird der Taster gedrückt, kann der Bewohner seine Wunschtemperatur eingeben. Wenn dies bei dem entsprechenden Durchlauf nicht der Fall ist, 
   wird gleich der Sensorwert eingelesen.
 * Je nachdem, wie niedrig die Temperatur ist, werden entweder zwei oder es wird nur eine oder aber gar keine LED angeschaltet 
  (stark, weniger stark oder gar nicht heizen').
 */
void loop() 
{
  tasterstatus = digitalRead(taster);
  
  if(tasterstatus == HIGH)                                    // Wenn der Taster gedrückt wird, wird Funktion leseWunschTemp ausgeführt.
  {
    leseWunschTemp();
  }
  sensorwert = analogRead(TMP36);                             // Auslesen des Sensorwertes.
  temperatur = map(sensorwert, 0, 410, -50, 150);             // Umwandeln des Sensorwertes in Werte zwischen -50 und 150° Celsius mit Hilfe des "map" Befehls.
  delay(t);                                                   // Nach jeder Messung ist je eine kleine Pause mit der Dauer „t“ in Millisekunden.
  Serial.print(temperatur);                                   // Nun wird der Wert „temperatur“ über die serielle Kommunikation an den PC gesendet. 
                                                              // Durch öffnen des seriellen Monitors in der Arduino-Software kann die Temperatur abgelesen werden.
  Serial.println(" Grad Celsius");                            // Im seriellen Monitor wird hinter der Temperatur die Einheit eingeblendet.


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
