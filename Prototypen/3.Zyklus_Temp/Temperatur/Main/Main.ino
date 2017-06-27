#include "Temperatursensor.h"

// erstellt eine Instanz der Klasse arduino mit dem Namen board
tempsensor board;

void setup() {
  board.init();
}

void loop(){
  int tasterstatus;
  if(tasterstatus == HIGH){               // Wenn der Taster gedrückt wird, wird Methode leseWunschTemp ausgeführt.
  board.leseWunschTemp(); 
  }
  else {
  delay(500);
  board.tempAnpassen();
  }
}


