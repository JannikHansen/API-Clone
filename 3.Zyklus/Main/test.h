#include setup_Rain.h

// Klasse für das Testing
class test
{
  public:
    void runTest();
  private:
    void rainTest();
    void printTestResult(const bool, const char*,const char*,const char*, const char*);
};
 PT2D rain;

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

//Methodendefinition für Feuchtigkeitstest auf Rückgabewert ungleich 0 (=true)(Jannik)
void test::rainTest(){
  int rain=rain.getRainValue();
  bool result = rain!=0;
  printTestResult (result,"Rain Test","Jannik Hansen","The return value of the moisture sensor gets checked", "test.h");
}

// Methode die alle Tests ausführt die dann in der Main ausgeführt werden kann
void test::runTest(){
  test::rainTest();
}
