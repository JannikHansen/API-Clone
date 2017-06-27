#include "arduino.h"
#include "test.h"

// erstellt eine Instanz der Klasse arduino mit dem Namen board
arduino board;

// erstellt eine Instanz der Klasse test mit dem Namen test und übergibt dem Konstruktor als Parameter das eben erstellte Board
test test(board);

void setup() {
  board.init();
  int rain = board.getRainValue();
  int light = board.getLightValue();
  int motion = board.getMotionValue();
  int temp = board.getTempValue();
  test.runTest();
}

void loop() {
  delay(5000);

  // Gibt Lichtwert zur Kontrolle des Tests aus
//  Serial.print("light: ");
 // Serial.println(light);
}
