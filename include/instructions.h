// -------- Includes --------
#include <stdint.h>

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

// -------- End of includes --------

// -------- Regular instructions prototypes --------
// 0x20 JR NZ,e8
void _20_jr_nz_e8(Gameboy *gb, uint8_t *args);

// 0x21 LD HL,n16
void _21_ld_hl_n16(Gameboy *gb, uint8_t *args);

// 0x31 LD SP,n16
void _31_ld_sp_n16(Gameboy *gb, uint8_t *args);

// 0x32 LD [HL-],A
void _32_ld_hld_a(Gameboy *gb);

// 0xAF XOR A
void _af_xor_a(Gameboy *gb);

// -------- End of regular instructions prototypes --------

// -------- CB prefixed instructions prototypes --------

// 0x7C BIT 7,H
void _cb_bit(uint8_t bit, uint8_t *r, uint8_t *f, uint32_t *t_state);
