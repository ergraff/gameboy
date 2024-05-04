#include <stdio.h>
#include <stdlib.h>

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

#define DEBUG

int main(int argc, char **argv) {
  Gameboy *gameboy = initialize();
  load_dmg_rom(gameboy);
  run(gameboy);

  #ifdef DEBUG
  printf("Final t_state: %d\n", gameboy->t_state);
  #endif

  free(gameboy);
  return 0;
}
