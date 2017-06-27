#include "arduino.h"
#include "test.h"

// erstellt eine Instanz der Klasse arduino mit dem Namen board
arduino board;

// erstellt eine Instanz der Klasse test mit dem Namen test und übergibt dem Konstruktor als Parameter das eben erstellte Board
test test(board);

void setup() {
  board.init();
}

void loop() {
  delay(5000);
  board.motorBewegen(light);

}

void loop(){
  delay(500);
  board.tempAnpass(temp);
}

