#include <Stepper.h>
Stepper Motor(2048, 28,24,26,22);
#define LightPort A4
#define LichtTaster 7



class Rollo_Licht
{
  public:
    int getLightValue();
    void Motorbewegen(int);
    int drehwinkel;
    int wunschlicht;
    int leseWunschLicht();
};

Rollo_Licht RolloLicht;
Rollo_Licht RLTest;

int Rollo_Licht::getLightValue()
{
  int messwert=analogRead(LightPort);
  return messwert;
}

void Rollo_Licht::Motorbewegen(int Helligkeit)
{
  this->wunschlicht=wunschlicht;
  if(Helligkeit>wunschlicht){
    Motor.step(-512);
    drehwinkel-512;
  }
  // Wenn der Helligkeitswert 400 unterschritten wird, dreht sich der Motor um eine viertel Umdrehung
  if(Helligkeit<wunschlicht){
    Motor.step(512);
    drehwinkel+=512;
  }
  this->drehwinkel=drehwinkel;
}


int Rollo_Licht::leseWunschLicht()
{
  char X_buffer[4]; 

  Serial.print("Geben Sie Ihre gewünschte Lichtstärke ein: ");
  this->wunschlicht=wunschlicht;
  if(wunschlicht == 0)
  {
    if (Serial.available())                                           // überprüft, ob Daten an den Arduino gesendet werden (returns true, wenn der serielle Puffer nicht leer ist)
    {
      Serial.flush();                                                 // wartet, bis alle seriellen Daten gesendet wurden
      delay(5); 
      for(int i=0;i<5;i++)
      {
        X_buffer[i] = Serial.read();                                  // liest nacheinander vier Zeichen ein und gibt sie als string zurück
      }
      Serial.flush();
      wunschlicht = atoi(X_buffer);                                    
      Serial.println(wunschlicht);
      return wunschlicht;
    } 
  }
}

