// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

// -------- End of includes --------

// -------- Regular instructions prototypes --------
// 0x0C INC C
void _0c_inc_c(Gameboy *gb);

// 0x0E LD C,n8
void _0e_ld_c_n8(Gameboy *gb, uint8_t *args);

// 0x11 LD DE,n16
void _11_ld_de_n16(Gameboy *gb, uint8_t *args);

// 0x1A LD A,[DE]
void _1a_ld_a_de(Gameboy *gb);

// 0x20 JR NZ,e8
void _20_jr_nz_e8(Gameboy *gb, uint8_t *args);

// 0x21 LD HL,n16
void _21_ld_hl_n16(Gameboy *gb, uint8_t *args);

// 0x31 LD SP,n16
void _31_ld_sp_n16(Gameboy *gb, uint8_t *args);

// 0x32 LD [HL-],A
void _32_ld_hld_a(Gameboy *gb);

// 0x3E LD A,n8
void _3e_ld_a_n8(Gameboy *gb, uint8_t *args);

// 0x77 LD [HL],A
void _77_ld_hl_a(Gameboy *gb);

// 0xAF XOR A
void _af_xor_a(Gameboy *gb);

// 0xCD CALL a16
int _cd_call_a16(Gameboy *gb, uint8_t *args);

// 0xE0 LD [0xFF00+a8],A
void _e0_ld_a8_a(Gameboy *gb, uint8_t *args);

// 0xE2 LD [0xFF00+C],A
void _e2_ld_c_a(Gameboy *gb);

// -------- End of regular instructions prototypes --------

// -------- CB prefixed instructions prototypes --------
// 0x7C BIT 7,H
void _cb_bit(uint8_t bit, uint8_t *r, uint8_t *f, uint32_t *t_state);

// -------- End of CB prefixed instructions prototypes --------
