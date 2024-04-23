#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#include "gb.h"

int main(int argc, char **argv) {
  Gameboy gameboy = gameboy_initialize();
  load_dmg_rom(&gameboy);

  printf("\n\n");

  CPU *cpu = &gameboy.cpu;
  uint8_t *mem = gameboy.mem;
  for (int i = 0; i < 10; i++) {
    uint8_t op = fetch_op(cpu, mem);
    printf("%02hhX ", op);
  }
  printf("\n");
}
