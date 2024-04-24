#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#define DEBUG

#include "gb.h"

int main(int argc, char **argv) {
  Gameboy gameboy = initialize();
  load_dmg_rom(&gameboy);

  run(&gameboy);

  return 0;
}
