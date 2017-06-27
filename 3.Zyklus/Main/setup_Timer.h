//T I M E R _ S T E L L W E R T E
//Timer 1
unsigned long previousMillis_1 = 0;                   // speichert wie viele Sekunden seit derletzten Änderung vergangen sind
unsigned long interval_1 = 5000;                      // Interval zwischen zwei Änderungen in millisek (1000 = 1sek)
//Timer 2
unsigned long previousMillis_2 = 0;
unsigned long interval_2 = 10000;

//T I M E R V A R I A B L E N
unsigned long time;

//T I M E R _ M E T H O D E N
void testausgabe (unsigned long zeitpunkt, const int timernr){
  Serial.println(" ");
  Serial.print("at time :");
  Serial.print(zeitpunkt);
  Serial.println(" sek");
  Serial.print("Funktionsausführung_");
  Serial.println(timernr);

}
