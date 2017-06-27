int LED=5;                                          //LED liegt auf Pin 5
int bewegung=7;                                     //Bewegungsmelder liegt auf Pin 7.
int bewegungsstatus=0;                              //Das Wort „bewegungsstatus“ steht jetzt zunächst für den Wert 0. Später wird unter dieser Variable gespeichert, ob eine Bewegung erkannt wird oder nicht.

void setup() 
{
pinMode(LED, OUTPUT);                               
pinMode(bewegung, INPUT);                           //Der Pin mit dem Bewegungsmelder (Pin 7) ist jetzt ein Eingang.
}

void loop(){
bewegungsstatus=digitalRead(bewegung);              //hier wird der Pin7 ausgelesen. Variablen „bewegungsstatus“ mit dem Wert „HIGH“ für 5Volt oder „LOW“ für 0Volt speichern.
if (bewegungsstatus == HIGH)                        //digitalRead (einlesen) ist das Gegenstück zu digitalWrite (ausgeben) und kann HIGH oder LOW ausgeben.
{
digitalWrite(LED, HIGH);                            //LED-Pin ein.
delay(5000);                                       
digitalWrite(LED, LOW);                             //LED-Pin aus.
}
else
{
digitalWrite(LED, LOW);                             //LED aus
}
}
