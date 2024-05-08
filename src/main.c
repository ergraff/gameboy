#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

#define DEBUG

int main(int argc, char **argv) {
  // Initialize
  Gameboy *gameboy = initialize();

  // Load bootstrap ROM into memory
  load_dmg_rom(gameboy);

  // Launch gameboy
  run(gameboy);

  #ifdef DEBUG
  printf("Final t_state: %d\n", gameboy->t_state);
  #endif

  // Free memory
  free(gameboy);

  return 0;
}
