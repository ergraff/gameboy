// -------- Includes --------
#include <stdio.h>
#include <stdint.h>

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "instructions.h"
#endif

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

#define DEBUG

// -------- End of includes --------

// -------- Regular instructions definitions --------

// 0x0E LD C,n8
void _0e_ld_c_n8(Gameboy *gb, uint8_t *args) {
  gb->C = args[0];

  gb->t_state += 8;

  #ifdef DEBUG
  printf("LD C,%02X (C=%02X)\t", args[0], gb->C);
  #endif
}

// 0x20 JR NZ,e8
void _20_jr_nz_e8(Gameboy *gb, uint8_t *args) {
  int8_t jump = (int8_t) args[0];
  if ((gb->F & 128) == 0) {
    gb->PC += jump;
    gb->t_state += 12;
  } else {
    gb->t_state += 8;
  }
  
  #ifdef DEBUG
  printf("JR NZ,%d\t", jump);
  #endif
}

// 0x21 LD HL,n16
void _21_ld_hl_n16(Gameboy *gb, uint8_t *args) {
  uint8_t low = args[0];
  uint8_t high = args[1];
  gb->H = high;
  gb->L = low;

  gb->t_state += 12;

  #ifdef DEBUG
  printf("LD HL,%02X%02X (HL=%02X%02X)\t", high, low, gb->H, gb->L);
  #endif
}

// 0x31 LD SP,n16
void _31_ld_sp_n16(Gameboy *gb, uint8_t *args) {
  uint16_t a = (uint16_t) args[0];
  uint16_t b = (uint16_t) args[1];
  uint16_t arg = (b << 8) | a;
  gb->SP = arg;

  gb->t_state += 12;

  #ifdef DEBUG
  printf("LD SP,%04X (SP=%04X)\t", arg, gb->SP);
  #endif
}

// 0x32 LD [HL-],A
void _32_ld_hld_a(Gameboy *gb) {
  uint16_t low = (uint16_t) gb->L;
  uint16_t high = (uint16_t) gb->H;
  uint16_t addr = (high << 8) | low;
  gb->mem[addr] = gb->A;

  uint16_t addr_new = addr - 1;
  uint8_t low_new = (uint8_t) addr_new;
  uint8_t high_new = (uint8_t) (addr_new >> 8);
  gb->H = high_new;
  gb->L = low_new;

  gb->t_state += 8;

  #ifdef DEBUG
  printf("LD [HL-],A (*[HL]=%02X, HL:%04X->%04X, H=%02X, L=%02X)\t", gb->mem[addr], addr, addr_new, gb->H, gb->L);
  #endif  
}

// 0x3E LD A,n8
void _3e_ld_a_n8(Gameboy *gb, uint8_t *args) {
  gb->A = args[0];

  gb->t_state += 8;

  #ifdef DEBUG
  printf("LD A,%02X (A=%02X)\t", args[0], gb->A);
  #endif
} 

// 0xAF XOR A
void _af_xor_a(Gameboy *gb) {
  gb->A = gb->A ^ gb->A; 

  gb->t_state += 4;

  #ifdef DEBUG
  printf("XOR A (A=%02X)\t", gb->A);
  #endif
}

// -------- End of regular instructions definitions --------

// -------- CB prefixed instructions definitions --------

// 0x7C BIT 7,H
void _cb_bit(uint8_t bit, uint8_t *r, uint8_t *f, uint32_t *t_state) {
  uint8_t shift = 7 - bit;
  uint8_t rr = ((*r << shift) & 128) ^ 128;
  *f = (*f & 127) | rr;

  *t_state += 8;

  #ifdef DEBUG
  uint8_t c = (*r >> 7) & 1;
  uint8_t z = (*f >> 7) & 1;
  printf("BIT 7,H (!r[7]=%d, Z=%d)\t", c,  z);
  #endif
}


// -------- End of CB prefixed instructions definitions --------
