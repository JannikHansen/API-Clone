#include "Bewegungsmelder.h"

#include <SPI.h>                             // SPI-Bibiothek hinzufügen

#include <MFRC522.h>                         // RFID-Bibiothek hinzufügen

#define SS_PIN 53                            // SDA an Pin 53

#define RST_PIN 5                            // RST an Pin 5                                       

MFRC522 mfrc522(SS_PIN, RST_PIN);            // RFID-Empfänger benennen

const long int AuthorizedCard = 1001330;     // Authorisierte Karte



motionsensor motion (4,45);

long int code=0;                             //Initialisierung einer Variable, die später die RFID-Kennung beherbergt.

bool detected=false;                         // Initialisierung einer Variable, die später auf true gesetzt wird, wenn eine authorisierte Karte erkannt wurde



void setup()                                // Beginn des Setups

{
  Serial.begin(9600);                       // Serielle Verbindung starten (Monitor)

  SPI.begin();                              // SPI-Verbindung aufbauen

  mfrc522.PCD_Init();                       // Initialisierung des RFID-Empfängers

  pinMode (3, OUTPUT);                      // Der Pin 3 ist jetzt ein Ausgang (Hier wird eine LED angeschlossen zur visuellen Überprüfung, ob Authentifizierung erfolgreich war)

  motion.initMotion();
}



void loop() 
{


// WENN NOCH KEINE KARTE ERKANNT WURDE, WIRD DIESER LOOP AUSGEFUEHRT

  if (detected==false){                         
      if ( ! mfrc522.PICC_IsNewCardPresent())   // Wenn keine Karte in Reichweite ist...
      {

      return; // gehe weiter...
      }
      if ( ! mfrc522.PICC_ReadCardSerial())     // Wenn kein RFID-Sender ausgewählt wurde
      {
      return; // gehe weiter...
      }


  

      for (byte i = 0; i < mfrc522.uid.size; i++)
      {
        code=((code+mfrc522.uid.uidByte[i])*10);  // Auslesen des Codes und Multiplikation der einzelnen Elemente mit dem Wert 10 
      }

      Serial.print("Erkannte Kartennummer:");
      Serial.println(code);


      //Hier beginnt die Identitaetsuebepruefung

  
      if (code==AuthorizedCard) {                // Wenn die Karte authorisiert ist..
        detected=true;                           // Setze "detected" auf true
    
        Serial.println("BERECHTIGT");            // .. dann wird "BERECHTIGT" auf dem Bildschirm ausgegeben..
        for (int i=0; i<3; i++)                  // ..und die LED an Pin 2 leuchtet drei Mal für 0,2 Sekunden auf.
        {
          digitalWrite (3, HIGH); 
          delay (200);
          digitalWrite (3, LOW);
          delay (200);
        }
      }

      else{ 
        Serial.println("NICHT BERECHTIGT");     // Wenn der Zahlencode nicht mit dem des RFID übereinstimmt wird eine Fehlermeldung ausgegeben
        detected=false;                         // Setze "detected" auf false
        code=0;                                 // Variable code wird zurueck auf Null gesetzt
      }
  }

  //WENN EINE KARTE ERKANNT WURDE, WIRD DIESER LOOP AUSGEFUEHRT

  else if (detected){
    motion.runMotion();                        // Starte Bewegungsmelder-Funktion
  }
} 
  

