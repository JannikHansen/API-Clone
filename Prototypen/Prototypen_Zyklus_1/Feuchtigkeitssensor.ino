int messwert=0;                                               //Variablendeklaration

void setup() 
{
  Serial.begin(9600);                                        //Die Kommunikation mit dem seriellen Port wird gestartet.
}

void loop()
{
  messwert=analogRead(A0);                                  //Die Spannung an dem Sensor wird (an Pin A0) ausgelesen und unter der Variable „messwert“ gespeichert.

  Serial.print("Feuchtigkeits-Messwert:");                  // Serielle Ausgabe

  Serial.println(messwert);

  delay(500);                                               // Pause zwischen Messungen
}
