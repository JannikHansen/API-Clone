#define light_port 4                                      // Definition der Anschlüsse
#define motion_port 45

bool detected=false;                                           // Initialisierung einer Variable bool (initial auf false)

class motionsensor {                                      // Klasse motionsensor enthaelt
  public:
    void initMotion ();                                   // Setup
    void runMotion ();                                    // Ablaufsteuerung fuer den Bewegungssensor
};


void motionsensor::initMotion () {                        // Setup
  pinMode(light_port, OUTPUT); 
  pinMode(motion_port, INPUT); 
}


void motionsensor::runMotion () {                         // Methodendefinition
    int bewegungsstatus=0; 
    bewegungsstatus = digitalRead(motion_port);           // Auslesen des Pins "motion_port". Das Ergebnis wird unter der Variablen "bewegungsstatus" mit dem Wert "HIGH" fuer 5 Volt oder "LOW" fuer 0Volt gespeichert.
    if (bewegungsstatus == HIGH)                          // Verarbeitung: Wenn eine Bewegung detektiert wird (Das Spannungssignal ist hoch)
    { 
      digitalWrite(light_port, HIGH);                     // dann leuchtet die LED auf
      delay(500);                                         // ...und zwar fuer 0,5 Sekunden.
      digitalWrite(light_port, LOW);
    } 
    else                                                  // Wenn keine Bewegung detektiert wird..
    { 
      digitalWrite(light_port, LOW);                      // ... soll LED aus sein.
    } 
 }
