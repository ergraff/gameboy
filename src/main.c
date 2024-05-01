#include <stdio.h>
#include <stdlib.h>

#ifndef GB_H
#define GB_H
#include "gb.h"
#endif

int main(int argc, char **argv) {
  Gameboy *gameboy = initialize();
  load_dmg_rom(gameboy);
  run(gameboy);

  free(gameboy);
  return 0;
}
