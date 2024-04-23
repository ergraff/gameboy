#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#include "gb.h"

int main(int argc, char **argv) {
  printf("Hello, world!\n");
  Gameboy gameboy = gameboy_initialize();
  load_dmg_rom(&gameboy);
}
