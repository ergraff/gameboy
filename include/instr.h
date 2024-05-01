// -------- Includes --------
#include <stdint.h>

#ifndef GB_H
#define GB_H
#include "gb.h"
#endif

// -------- End of includes --------

// -------- Instructions prototypes --------
// 0x21 LD HL,n16
void _21_ld_hl_n16(Gameboy *gb, uint8_t *args);

// 0x31 LD SP,n16
void _31_ld_sp_n16(Gameboy *gb, uint8_t *args);

// 0x32 LD [HL-],A
void _32_ld_hld_a(Gameboy *gb);

// 0xAF XOR A
void _af_xor_a(Gameboy *gb);

// -------- End of instructions prototypes --------
