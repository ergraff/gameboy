#include <stdio.h>
#include <stdlib.h>

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

int main(int argc, char **argv) {
  Gameboy *gameboy = initialize();
  load_dmg_rom(gameboy);
  run(gameboy);

  free(gameboy);
  return 0;
}
