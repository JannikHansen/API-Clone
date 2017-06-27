// Klasse für das Testing
class test{
  public:
    test(arduino);
    void runTest();  
  private:
    void lightTest();
    void rainTest();
    void motionTest();
    void tempTest();
    void printTestResult(const bool, const char*,const char*,const char*);
    arduino board;
};

// Konstruktor erwartet als Parameter die Arduino-Klasse
test::test(arduino board2){
  this->board=board2;
}

// Gibt Testergebnis aus
// result ist das Testergebnis mit true = success und false = Fail
// TestName ist der Name des Tests
// author ist Name des Test Autors
// testFall Ist eine Beschreibung was bei dem Test getestet wird
void test::printTestResult(const bool result, const char* testName, const char* author, const char* testFall){
    Serial.print("Test: ");
    Serial.println(testName);
    Serial.print("\tGeschrieben von: ");
    Serial.println(author);
    Serial.print("\tWas wird getestet: ");
    Serial.println(testFall);
    if(result){
      Serial.println("--------Success--------");
    }else{
      Serial.println("--------Fail--------");
    }
}

// Methode für Lichttest auf gültigen Rückgabewert (Tammo)
void test::lightTest(){
  int light=board.getLightValue();
  bool result = light!=0;
  printTestResult(result,"Light Test","Tammo Stein","The return value of the light sensor gets checked");
}
//Methodendefinition für Feuchtigkeitstest auf Rückgabewert ungleich 0 (=true)(Jannik)
void test::rainTest(){
  int rain=board.getRainValue();
  bool result = rain!=0;
  printTestResult (result,"Rain Test","Jannik Hansen","The return value of the moisture sensor gets checked");
}
//Methode für Bewegungssensortest auf gültigen Rückgabewert (Niklas)
void test::motionTest(){
  int motion=board.getMotionValue();
  bool result = motion!=0;
  printTestResult(result,"Motion Test","Niklas Holz","The return value of the motion sensor gets checked");
}
// Methode für Temperatursensortest auf gültigen Rückgabewert (Nerea)
void test::tempTest(){
  int temp=board.getTempValue();
  bool result = temp!=0;
  printTestResult(result,"Temp Test","Nerea Meinicke","The return value of the temperature sensor gets checked");
}

// Methode die alle Tests ausführt die dann in der Main ausgeführt werden kann
void test::runTest(){
  test::lightTest();
  test::rainTest();
  test::motionTest();
  test::tempTest();
}

