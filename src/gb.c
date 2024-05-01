// -------- Includes --------
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef GB_H
#define GB_H
#include "gb.h"
#endif

#ifndef INSTR_H
#define INSTR_H
#include "instr.h"
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
    memset(gameboy->mem, 0, MEM_SIZE);
    gameboy->A = 0;
    gameboy->B = 0;
    gameboy->C = 0;
    gameboy->D = 0;
    gameboy->E = 0;
    gameboy->F = 0;
    gameboy->H = 0;
    gameboy->L = 0;
    gameboy->SP = 0;
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
uint8_t get_pc_val(Gameboy *gb) {
  uint16_t addr = gb->PC;
  uint8_t op = gb->mem[addr];
  return op;
}
/*
  Helper function to load two bytes into args and advance the program counter twice
*/
void get_n16(Gameboy *gb, uint8_t *args) {
    args[0] = get_pc_val(gb);
    gb->PC++;
    args[1] = get_pc_val(gb);
    gb->PC++;
}

/*
  The function that reads and delegates the current instruction to their individual functions
*/
int perform_instruction(Gameboy *gb) {
  int res = 0;

  // Read current instruction
  uint8_t instr = get_pc_val(gb);

  #ifdef DEBUG
  // Print current memory location
  printf("0x%04hhX: ", gb->PC);
  #endif

  // Advance program counter
  gb->PC++;

  // Array to hold arguments
  uint8_t args[2] = {0};

  // Check instruction
  switch (instr) {

    // 0x21 LD HL,n16
    case 0x21:
      get_n16(gb, args);
      _21_ld_hl_n16(gb, args);
      break;

    // 0x31 LD SP,n16
    case 0x31:
      get_n16(gb, args);
      _31_ld_sp_n16(gb, args);
      break;

    // 0x32 LD [HL-],A
    case 0x32:
      _32_ld_hld_a(gb);
      break;

    // 0xAF XOR A
    case 0xAF:
      _af_xor_a(gb);
      break;

    // Default case, the instruction has not been defined.
    default:
      res = 1;
      break;
  }

  #ifdef DEBUG
  // Print instruction and arguments
  printf("%02X ", instr);
  for (int i = 0; i < 2; i++) {
    int a = args[i];
    if (a > 0) {
      printf("%02X ", a);
    }
  }
  printf("\n");
  #endif

  // Check return message
  if (res > 0) {
    printf("gb.c:perform_instruction(): Instruction '%02X' has not been defined!\n", instr);
  }

  return res;
}

/*
  Starts running the commands located in memory
*/
int run(Gameboy *gb) {
  // Read instructions until end
  while (get_pc_val(gb) != 0) {
    // Perform instruction
    int res = perform_instruction(gb);

    // Read return result
    if (res > 0) {
      // Something went wrong
      printf("gb.c:run() Something went wrong, exiting...\n");
      break;
    }
  }
  return 0;
}

// -------- End of functions --------
