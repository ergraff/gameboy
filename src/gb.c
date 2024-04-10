// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
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

// -------- End of emory definitions --------

// -------- Gameboy definitions --------
/*
  Struct to hole the Gameboy device
*/

typedef struct Gameboy {
  /*
    Memory
  */
  uint16_t mem[MEM_SIZE];

  /*
    Registers
  */
  uint16_t AF; // A and F
  uint16_t BC; // B and C
  uint16_t DE; // D and E
  uint16_t HL; // H and L
  uint16_t SP; // Stack pointer
  uint16_t PC; // Program counter

} Gameboy;

// -------- End of Gameboy definitions --------
