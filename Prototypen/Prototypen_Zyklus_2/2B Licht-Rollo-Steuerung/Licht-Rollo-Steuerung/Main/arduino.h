#include <stepper.h>
#define LightPort A4
#define RainPort A2
#define MotionPort 44
#define TempPort A0


// Klasse die das Arduinoboard repressentiert und die nötigen Funktionen beinhaltet
class arduino {
  public:
    void init();
    int getLightValue();
    int getRainValue();
    int getMotionValue();
    int getTempValue();
    void motorBewegen();
    int drehwinkel;
  private:
    int SPU = 2048;
};

// Initiallierung des Boards und zuweisung der Ports
void arduino::init(){
  // Beginnt die Übertragung an den seriellen Monitor
  Serial.begin(9600);
  Stepper Motor(SPU, 28,24,26,22);
  pinMode(LightPort,INPUT);
  pinMode(RainPort,INPUT);
  pinMode(MotionPort,INPUT);
  pinMode(TempPort,INPUT);
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
int arduino::getTempValue(){
  int messwert=analogRead(TempPort);
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
