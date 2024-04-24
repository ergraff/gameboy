#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#include "gb.h"

int main(int argc, char **argv) {
  Gameboy gameboy = initialize();
  load_dmg_rom(&gameboy);

  printf("\n");

  run(&gameboy);

  return 0;
}
