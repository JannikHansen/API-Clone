int TMP36 = A0;                                           //Der Sensor soll am analogen Pin A0 angeschlossen werden. Wir nennen den Pin ab jetzt "TMP36"
int sensorwert;
int temperatur = 0;                                       //Unter der Variablen "temperatur" wird später der Temperaturwert abgespeichert.
int t=500;                                                //Der Wert für „t“ gibt im Code die zeitlichen Abstände zwischen den einzelnen Messungen vor.

void setup() 
{
Serial.begin(9600);                                       //Im Setup beginnt die serielle Kommunikation, damit die Temperatur an den serial monitor übertragen wird. Über die serielle Kommunikation sendet das Board die Messwerte an den Computer. In der Arduino-Software kann man unter „Werkzeuge“ den „Seriellen Monitor“ starten um die Messwerte zu sehen.
pinMode(4 , OUTPUT);
}

void loop() 
{
sensorwert=analogRead(TMP36);                             //Auslesen des Sensorwertes.
temperatur= map(sensorwert, 0, 410, -50, 150);            //Umwandeln des Sensorwertes mit Hilfe des "map" Befehls.
delay(t);                                                 // Nach jeder Messung ist je eine kleine Pause mit der Dauer „t“ in Millisekunden.
Serial.print(temperatur);                                 //Nun wird der Wert „temperatur“ über die serielle Kommunikation an den PC gesendet. Durch öffnen des seriellen Monitors in der Arduino-Software kann die Temperatur abgelesen werden.
Serial.println(" Grad Celsius");                          // Im seriellen Monitor wird hinter der Temperatur die Einheit eingeblendet.

//Nicht Anleitungs-Code (Schaltet LED bei zu hoher Temp. aus)

if(temperatur<=30)
digitalWrite(4, HIGH);
else
digitalWrite(4, LOW);
}
