class motionsensor {                                      // Klasse motionsensor enthaelt
  private:
    int light;                                            // Variable, die später den LED-Anschluss definiert
    int bewegung;                                         // Variable, die später den Bewegungsmelderanschluss definiert
  public:
    motionsensor (int light, int bewegung);               // Konstruktor (bekommt Anschluesse fuer LED und Bewegungssensor uebergeben)
    void initMotion ();                                   // Setup
    void runMotion ();                                    // Ablaufsteuerung fuer den Bewegungssensor
};

motionsensor::motionsensor (int light, int bewegung){     // Konstruktordefinition
  this->light = light;
  this->bewegung = bewegung;
}


void motionsensor::initMotion () {                        // Setup
  pinMode(light, OUTPUT); 
  pinMode(bewegung, INPUT); 
}


void motionsensor::runMotion () {                         // Methodendefinition
    int bewegungsstatus=0; 
    bewegungsstatus = digitalRead(bewegung);              // Auslesen von Pin "bewegung". Das Ergebnis wird unter der Variablen "bewegungsstatus" mit dem Wert "HIGH" fuer 5 Volt oder "LOW" fuer 0Volt gespeichert.
    if (bewegungsstatus == HIGH)                          // Verarbeitung: Wenn eine Bewegung detektiert wird (Das Spannungssignal ist hoch)
    { 
      digitalWrite(light, HIGH);                          // dann leuchtet die LED auf
      delay(500);                                         // ...und zwar fuer 0,5 Sekunden.
      digitalWrite(light, LOW);
      delay(500);
    } 
    else                                                  // Wenn keine Bewegung detektiert wird..
    { 
      digitalWrite(light, LOW);                           // ... soll LED aus sein.
    } 
 }
