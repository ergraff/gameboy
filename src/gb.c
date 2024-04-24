// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef INSTR_H
#define INSTR_H
#include "instr.h"
#endif

// -------- End of includes --------
 
// -------- Memory definitions --------
/*
  Total memory size
*/
#define MEM_SIZE    0xFFFF

/*
  Memory regions
*/
#define BANK_ZERO   0x0000
#define BANK_ONE    0x4000
#define VRAM        0x8000
#define EXT_RAM     0xA000
#define WRAM_ZERO   0xC000
#define WRAM_ONE    0xD000
#define ECHO_RAM    0xE000
#define OAM         0xFE00
#define IO_REG      0xFF00
#define HRAM        0xFF80
#define INTR        0xFFFF

/*
  RST addresses
*/
#define RST1        0x0000
#define RST2        0x0008
#define RST3        0x0010
#define RST4        0x0018
#define RST5        0x0020
#define RST6        0x0028
#define RST7        0x0030
#define RST8        0x0038

/*
  Interrupt adresses
*/
#define INTR1       0x0040
#define INTR2       0x0048
#define INTR3       0x0050
#define INTR4       0x0058
#define INTR5       0x0060

// -------- End of memory definitions --------

// -------- Gameboy definitions --------
/*
  Struct to hold the Gameboy device
*/

typedef struct Gameboy {
  /*
    Memory
  */
  uint8_t mem[MEM_SIZE];

  /*
    Registers
  */
  uint8_t A;
  uint8_t B;
  uint8_t C;
  uint8_t D;
  uint8_t E;
  uint8_t F;
  uint8_t H;
  uint8_t L;

  /*
    Pointers
  */
  uint16_t SP;
  uint16_t PC;

} Gameboy;

// -------- End of Gameboy definitions --------

// -------- Functions --------
Gameboy initialize() {
  Gameboy gameboy = {{0}, 0, 0, 0,0, 0, 0, 0, 0, 0, 0};
  return gameboy;
}

int load_dmg_rom(Gameboy *gb) {
  FILE *fptr;
  size_t rom_len = 256;
  uint8_t rom[256] = {0};

  // Open ROM
  char *file = "./bin/DMG_ROM.bin";
  fptr = fopen(file, "rb");
  if (fptr == NULL) {
    printf("Could not read file '%s'\n", file);
    return 1;
  }

  // Read ROM
  fread(rom, rom_len, 1, fptr);

  // Write ROM to GB memory
  for (int i = 0; i < rom_len; i++) {
    gb->mem[i] = rom[i];
  }

  fclose(fptr);

  // DEBUG Print ROM
  for (int i = 0; i < rom_len; i++) {
    uint8_t r = gb->mem[i];
    printf("%02hhX ", r);
  }
  printf("\n");

  return 0;
}

uint8_t current_instruction(Gameboy *gb) {
  uint16_t addr = gb->PC;
  uint8_t op = gb->mem[addr];
  return op;
}













// -------- End of functions --------
