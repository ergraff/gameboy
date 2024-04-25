#include <stdio.h>
#include <stdlib.h>

#include "gb.h"

int main(int argc, char **argv) {
  Gameboy *gameboy = initialize();
  load_dmg_rom(gameboy);
  run(gameboy);

  free(gameboy);
  return 0;
}
