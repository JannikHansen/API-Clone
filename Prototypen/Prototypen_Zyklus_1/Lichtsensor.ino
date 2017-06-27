int eingang= A0;                                           //Das Wort „eingang“ steht jetzt für den Wert „A0“ (Bezeichnung vom Analogport 0)
int LED = 10;                                              //Das Wort „LED“ steht jetzt für den Wert 10
int sensorWert = 0;                                        //Variable für den Sensorwert mit 0 als Startwert

void setup()
{
Serial.begin(9600);                                        //Die Kommunikation mit dem seriellen Port wird gestartet.
pinMode (LED, OUTPUT);                                     //Der Pin mit der LED (Pin 10) ist jetzt ein Ausgang  //Der analoge Pins mussen nicht definiert werden.
}

void loop()
{
sensorWert =analogRead(eingang);                           //Die Spannung an dem Fotowiderstand auslesen und unter der Variable „sensorWert“ abspeichern.
Serial.print("Sensorwert = " );
Serial.println(sensorWert);                                //Ausgabe am Serial-Monitor in Form einer Zahl zwischen 0 und 1023.
delay (1000);
}
