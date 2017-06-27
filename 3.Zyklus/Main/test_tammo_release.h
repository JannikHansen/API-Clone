
class test
{
  public:
    void runTest();
  private:
    void lightTest();
    void rainTest();
//    void motionTest();
//    void tempTest();
    void motorTest();
    void printTestResult(const bool, const char*,const char*,const char*, const char*);
    
};

// Gibt Testergebnis aus
// result ist das Testergebnis mit true = success und false = Fail
// TestName ist der Name des Tests
// author ist Name des Test Autors
// testFall Ist eine Beschreibung was bei dem Test getestet wird
void test::printTestResult(const bool result, const char* testName, const char* author, const char* testFall, const char* datei){
    Serial.print("Test: ");
    Serial.println(testName);
    Serial.print("\tGeschrieben von: ");
    Serial.println(author);
    Serial.print("\tWas wird getestet: ");
    Serial.println(testFall);
    Serial.print("\tName der Datei: ");
    Serial.println(datei);

    if(result){
      Serial.println("--------Success--------");
    }else{
      Serial.println("--------Fail--------");
    }
}

// Methode für Lichttest auf gültigen Rückgabewert (Tammo)
void test::lightTest(){
  int light=RLTest.getLightValue();
  bool result = light!=0;
  printTestResult(result,"Light Test","Tammo Stein","The return value of the light sensor gets checked", "test.h");
}
//Methodendefinition für Feuchtigkeitstest auf Rückgabewert ungleich 0 (=true)(Jannik)

void test::rainTest(){
  int rain=rain.getRainValue();
  bool result = rain!=0;
  printTestResult (result,"Rain Test","Jannik Hansen","The return value of the moisture sensor gets checked", "test.h");
}
/*
//Methode für Bewegungssensortest auf gültigen Rückgabewert (Niklas)
void test::motionTest(){
  int motion=board.getMotionValue();
  bool result = motion!=0;
  printTestResult(result,"Motion Test","Niklas Holz","The return value of the motion sensor gets checked", "test.h");
}
// Methode für Temperatursensortest auf gültigen Rückgabewert (Nerea)
void test::tempTest(){
  int temp=board.getTempValue();
  bool result = temp!=0;
  printTestResult(result,"Temp Test","Nerea Meinicke","The return value of the temperature sensor gets checked", "test.h");
}
*/
// Methode die alle Tests ausführt die dann in der Main ausgeführt werden kann
void test::runTest(){
  test::lightTest();
  test::motorTest();
  test::rainTest();
  //test::motionTest();
  //test::tempTest();
}

void test::motorTest()
{
    int light=RLTest.getLightValue();
    RLTest.Motorbewegen(light);
    bool result;
    if(RLTest.drehwinkel!=0){
      result=true;
    }
    else
    {
      result=true;
    }
    printTestResult(result, "Motor Test", "Tammo Stein", "Der korrekte Aufruf der motorbewegen-Funktion wird überprüft", "test.h");
}


