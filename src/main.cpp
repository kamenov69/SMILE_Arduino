#include <Arduino.h>
#include "board.h"
#include "globals.h"

void setup() {
  setup_board();

  setup_globals();
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_board();

}

