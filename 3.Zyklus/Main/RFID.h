
#include <SPI.h>                                  // SPI-Bibiothek hinzufuegen

#include <MFRC522.h>                              // RFID-Bibiothek hinzufuegen

#define SS_PIN 53                                 // SDA an Pin 53

#define RST_PIN 5                                 // RST an Pin 5        

#define led_Port 3                                // LED zur visuellen Bestätigung an Pin 3

MFRC522 mfrc522(SS_PIN, RST_PIN);                 // RFID-Empfaenger benennen

const long int AuthorizedCard = 1001330;          // Authorisierte Karte

long code=0;                                      // Initialisierung der Variable code (speichert später die eingelesene Kartennummer) 


  
class RFID {                                      // Klasse RFID enthaelt:  
  public:                                         // Öffentliche Methoden:
    void initRFID ();                             
    void start();
    void readCode();
    bool checkIdentity ();                       
};



void RFID::initRFID (){                           // 1. Methodendefinition
  
  SPI.begin();                                    // SPI-Verbindung aufbauen

  mfrc522.PCD_Init();                             // Initialisierung des RFID-Empfaengers
}

void RFID::start() {                              // 2. Methodendefiniton
  
  if ( ! mfrc522.PICC_IsNewCardPresent())         // Wenn eine Karte in Reichweite ist...
  {
    return;                                       // gehe weiter...
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial())           // Wenn ein RFID-Sender ausgewaehlt wurde
  {
    return;                                       // gehe weiter...
  }

}

void RFID::readCode() {                           // 3. Methodendefiniton
  
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    code=((code+mfrc522.uid.uidByte[i])*10);      // Einlesen des Codes und Multiplikation der einzelnen Elemente mit dem Wert 10 (dient zur Ausgabe einer sinnvolleren Karten-ID)
  }

 

  Serial.print("Erkannte Kartennummer:");         // Ausgabe der eingelesenen Kartennummer
  Serial.print(code);
 
}



bool RFID::checkIdentity(){                       // 4. Methodendefinition

  if (code==AuthorizedCard){                      // Wenn der eingelesene Code gleich dem authorisierten Code ist..
    Serial.print("BERECHTIGT");                   // .. dann wird "BERECHTIGT" auf dem Bildschirm ausgegeben..
    for (int i=0; i<3; i++) {                     // ..und die LED an Pin 2 leuchtet drei Mal fuer 0,5 Sekunden auf.
      digitalWrite (led_Port, HIGH); 
      delay (200);
      digitalWrite (led_Port, LOW);
    }
    return true;                                  // Rückgabe von "true"     (Wird in der Hauptfunktion einer Variable zugewiesen, anhand der entschieden wird, ob entweder die RFID-Erkennung oder die Ausführung der Teilfunktionen stattfindet)
    }    
 

   else {                                         // Wenn der eingelesene Code NICHT gleich dem authorisierten Code ist..
    code=0;                                       // Setze Variable Code zurück auf Null
    Serial.print("NICHT BERECHTIGT");             // Wenn der Zahlencode nicht mit dem des RFID uebereinstimmt wird eine Fehlermeldung ausgegeben
    return false;                                 // Rückgabe von "false"
   }
 
}


