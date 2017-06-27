//P O R T B E L E G U N G
#define RainPort A2
#define RainOUTPort 10

//S T E L L W E R T E
int rainmax = 300;

//K L A S S E N D E F I N I T I O N
class PT2D {                           
  public:
    void init();
    int getRainValue();
    void checkRain(int, int );
};

//M E T H O D E N D E F I N I T I O N
void PT2D::init(){
  Serial.begin(9600);
  pinMode(RainPort,INPUT);
  pinMode(RainOUTPort,OUTPUT);
}

int PT2D::getRainValue(){
  int messwert=analogRead(RainPort);
  return messwert;
}

void PT2D::checkRain(int rain, int maxrain){
  if (rain<maxrain) {
    digitalWrite(RainOUTPort, HIGH);   // schaltet RainOUTPort scharf.
    Serial.print("Rain: ");
    Serial.println(rain);
    Serial.println("RAIN ON");

  }
  else {
    digitalWrite(11, LOW);    // schaltet RainOUTPort stum.
    Serial.print("Rain: ");
    Serial.println(rain);
    Serial.println("RAIN OFF");
  }
}
