#include <stepper.h>
#define LightPort A4
#define RainPort A2
#define MotionPort 44
#define TempPort A0


// Klasse, die das Arduinoboard repräsentiert und die nötigen Funktionen beinhaltet
class arduino {
  public:
    void init();
    int getLightValue();
    int getRainValue();
    int getMotionValue();
    int getTempValue();
    void motorBewegen();
    int drehwinkel;
    void tempAnpassen();
  private:
    int SPU = 2048;
};

// Initialisierung des Boards und Zuweisung der Ports
void arduino::init(){
  // Beginnt die Übertragung an den seriellen Monitor
  Serial.begin(9600);
  Stepper Motor(SPU, 28,24,26,22);
  pinMode(LightPort,INPUT);
  pinMode(RainPort,INPUT);
  pinMode(MotionPort,INPUT);
  pinMode(TempPort,INPUT);

  pinMode(13, OUTPUT);			// Pin 13 und 11 als Output für die LEDs           
  pinMode(11, OUTPUT);			// der Temperatursteuerung

  int rain = board.getRainValue();
  int light = board.getLightValue();
  int motion = board.getMotionValue();
  int temp = board.getTempValue();
}

// Gibt den aktuellen Messwert des Photowiderstandes zurück
int arduino::getLightValue(){
  int messwert=analogRead(LightPort);
  return messwert;
}
// Methode zur Rückgabe des Fechtigkeistwertes aus dem Pin für F.Sensor
int arduino::getRainValue(){
  int messwert=analogRead(RainPort);
  return messwert;
}
//Methode zur Rückgabe des Wertes des Bewegungssensors
  int arduino::getMotionValue(){
  int messwert=digitalRead(MotionPort);
  return messwert;
}
// Methode zur Rückgabe des Temperaturwertes
// JETZT IN ° CELSIUS über map-Befehl
int arduino::getTempValue(){
  int sensorwert = analogRead(TempPort);
  messwert = map(sensorwert, 0, 410, -50, 150);
  return messwert;
}

// Methode fuer die Bewegung des Motors bei bestimmten Helligkeitswerten
void arduino::motorBewegen(int Helligkeit) {
  // Wenn der Helligkeitswert 650 überschritten wird dreht sich der Motor um eine viertel Umdrehung zurück
  if(Helligkeit>650){
    Motor.step(-512);
    drehwinkel=-512;
  }
  // Wenn der Helligkeitswert 400 unterschritten wird, dreht sich der Motor um eine viertel Umdrehung
  if(Helligkeit<400){
    Motor.step(512);
    drehwinkel=+512;
  }
}

// Methode für das Anschalten von keiner, einer LED oder zwei LEDs (nicht, ein wenig oder stark heizen)
void arduino::tempAnpassen (int temperatur){
  
if(temperatur <= 10) {                                        // Wenn die Temperatur kleiner als 10° Celsius werden beide LEDs angeschaltet (Heizung voll aufgedreht)
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
}
else if(temperatur > 10 && temperatur <= 22) {        // Ist die Temperatur zwar höher als 10° Celsius, aber noch unter Wunschtemperatur wird nur eine LED angeschaltet
  digitalWrite(13, HIGH);                                     // (Heizung läuft auf kleinerer Stufe).
  digitalWrite(11, LOW);
}
else if(temperatur > 22){                             // Ist der Wert größer oder gleich der Wunschtemperatur werden beide LEDs ausgeschaltet
  digitalWrite(13, LOW);                                      // (Heizung aus).
  digitalWrite(11, LOW);
}
}