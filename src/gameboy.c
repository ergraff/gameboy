// -------- Includes --------
#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STRING_H
#define STRING_H
#include <string.h>
#endif

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "instructions.h"
#endif

#ifndef INTERPRET_H
#define INTERPRET_H
#include "interpret.h"
#endif

#define DEBUG

// -------- End of includes --------
 
// -------- Functions --------
/*
  Returns a zeroed instance of the Gameboy struct
*/
Gameboy *initialize() {
  Gameboy *gameboy = malloc(sizeof *gameboy);
  if (gameboy) {
    gameboy->t_state = 0;
    memset(gameboy->mem, 0, MEM_SIZE);
    gameboy->AF = 0;
    gameboy->BC = 0;
    gameboy->DE = 0;
    gameboy->HL = 0;
    gameboy->SP = 0xFFFF;
    gameboy->PC = 0;
  }
  return gameboy;
}

/*
  Loads the bootstrap DMB_ROM.bin into memory starting from 0x0000
*/
int load_dmg_rom(Gameboy *gb) {
  FILE *fptr;
  size_t rom_len = 256;
  uint8_t rom[256] = {0};

  // Open ROM
  char *file = "./DMG_ROM.bin";
  fptr = fopen(file, "rb");
  if (fptr == NULL) {
    printf("gb.c:load_dmg_rom(): Could not read file '%s'\n", file);
    return 1;
  }

  // Read ROM
  fread(rom, rom_len, 1, fptr);

  // Write ROM to GB memory
  for (int i = 0; i < rom_len; i++) {
    gb->mem[i] = rom[i];
  }

  fclose(fptr);

  #ifdef DEBUG
  // Print ROM
  for (int i = 0; i < rom_len; i++) {
    uint8_t r = gb->mem[i];
    printf("%02hhX ", r);
  }
  printf("\n\n");
  #endif

  return 0;
}

/*
  Returns the value at the location of the current program counter
*/
uint8_t read_op(Gameboy *gb) {
  uint16_t addr = gb->PC;
  uint8_t op = gb->mem[addr];
  return op;
}

/*
  The function that reads the current instruction and performs it
*/
int perform_instruction(Gameboy *gb) {
  // Read current instruction
  uint8_t instr = read_op(gb);

  #ifdef DEBUG
  // Print current memory location
  printf("0x%04hhX: ", gb->PC);
  #endif

  // Advance program counter
  gb->PC++;

  // Interpret instruction
  int res = interpret(gb, instr);

  // Check return message
  // TODO: If more errors are added then separate to other file
  switch (res) {
    case 1:
      printf("gb.c:perform_instruction(): Instruction '%02X' has not been defined!\n", instr);
      break;
    case 2:
      printf("gb.c:perform_instruction(): Stack would overflow (SP=%04X)!\n", gb->SP);
      break;
  }

  return res;
}

/*
  Starts running the commands located in memory
*/
int run(Gameboy *gb) {
  // Read instructions until end
  while (read_op(gb) != 0) {
    // Perform instruction
    int res = perform_instruction(gb);

    // Read return result
  // TODO: If more errors are added then separate to other file
    if (res > 0) {
      // Something went wrong
      printf("gb.c:run(): Error encountered, exiting...\n");
      break;
    }
  }
  return 0;
}

// -------- End of functions --------
