 void setup() //Wir starten mit dem Setup
{
  pinMode(12, OUTPUT); // HeizungsLED in 12 Output 
}

void loop() // Das Hauptprogramm beginnt.
{
  digitalWrite(12, HIGH); // Schalte die HeizungLED an Pin12 an.
  delay(2000); //Testweise delay 
  digitalWrite(12, LOW); // ausschalten der LED
  delay(2000); 
  
}

