//Timer 1
unsigned long previousMillis_1 = 0;                   // speichert wie viele Sekunden seit derletzten Änderung vergangen sind
unsigned long interval_1 = 1000;                      // Interval zwischen zwei Änderungen in millisek (1000 = 1sek)
//timer 2
unsigned long previousMillis_2 = 0;
unsigned long interval_2 = 2000;

unsigned long time;
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  time = millis()/1000;                               // gebe Zeit in sek wieder für bessere Sichtbarkeit

  //Ausführen von Funktion 1 jede Sekunde und Ausgabe von Information über Zeitpunkt der Ausgabe
  if (millis() - previousMillis_1 > interval_1) {
    previousMillis_1 = millis();                      // aktuelle Zeit abspeichern
    Serial.println("Funktionsausführung_1");
    Serial.print("at time :");
    Serial.print(time);
    Serial.println(" sek");
  }
  //Ausführen von Funktion 2
  if (millis() - previousMillis_2 > interval_2) {
    previousMillis_2 = millis();
    Serial.println("Funktionsausführung_2");
    Serial.print("at time :");
    Serial.print(time);
    Serial.println(" sek");
  }
  return 0;
}

