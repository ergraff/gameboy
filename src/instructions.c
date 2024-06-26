// -------- Includes --------
#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

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
// 0x0C INC C
void _0c_inc_c(Gameboy *gb) {
  gb->C += 1;
  gb->t_state += 4;

  #ifdef DEBUG
  printf("INC C (C:%02X->%02X)\t", gb->C-1, gb->C);
  #endif
}

// 0x0E LD C,n8
void _0e_ld_c_n8(Gameboy *gb, uint8_t *args) {
  gb->C = args[0];
  gb->t_state += 8;

  #ifdef DEBUG
  printf("LD C,%02X (C=%02X)\t", args[0], gb->C);
  #endif
}

// 0x11 LD DE,n16
void _11_ld_de_n16(Gameboy *gb, uint8_t *args) {
  uint8_t low = args[0];
  uint8_t high = args[1];
  gb->D = high;
  gb->E = low;
  gb->t_state += 12;

  #ifdef DEBUG
  printf("LD DE,%02X%02X (DE=%02X%02X)\t", high, low, gb->D, gb->E);
  #endif
}

// 0x1A LD A,[DE]
void _1a_ld_a_de(Gameboy *gb) {
  gb->A = gb->mem[gb->DE];
  gb->t_state += 8;

  #ifdef DEBUG
  printf("LD A,[DE] (A=%02X, *[DE]=%02X)\t", gb->A, gb->mem[gb->DE]);
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
  gb->mem[gb->HL] = gb->A;
  gb->HL -= 1;
  gb->t_state += 8;

  #ifdef DEBUG
  printf("LD [HL-],A (*[HL]=%02X, HL:%04X->%04X, HL=%04X)\t", gb->mem[gb->HL], gb->HL+1, gb->HL, gb->HL);
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

// 0x77 LD [HL],A
void _77_ld_hl_a(Gameboy *gb) {
  gb->mem[gb->HL] = gb->A;
  gb->t_state += 8;
  
  #ifdef DEBUG
  printf("LD [HL],A (*[HL]=%02X)\t", gb->mem[gb->HL]);
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

// 0xCD CALL a16
int _cd_call_a16(Gameboy *gb, uint8_t *args) {
  // Overflow guard
  if (gb->SP <= 0xFF81) {
    printf("SP: %04X\n", gb->SP);
    return 2;
  }

  // Push PC to stack
  uint8_t pc_low = (uint8_t) gb->PC;
  uint8_t pc_high = (uint8_t) (gb->PC >> 8);
  gb->SP--;
  gb->mem[gb->SP] = pc_high;
  gb->SP--;
  gb->mem[gb->SP] = pc_low;

  // Set new PC
  uint16_t pc_old = gb->PC;
  uint8_t arg_low = args[0];
  uint8_t arg_high = args[1];
  uint16_t pc_new_low = (uint16_t) arg_low;
  uint16_t pc_new_high = (uint16_t) arg_high << 8;
  uint16_t pc_new = pc_new_high | pc_new_low;
  gb->PC = pc_new;

  gb->t_state += 24;
  
  #ifdef DEBUG
  printf("CALL %02X%02X (SP=%04X, *[SP]=%02X, *[SP+1]=%02X, PC=%04X->%04X)\t", \
         arg_high, arg_low, gb->SP, gb->mem[gb->SP], gb->mem[gb->SP+1], pc_old, gb->PC);
  #endif

  return 0;
}

// 0xE0 LD [0xFF00+a8],A
void _e0_ld_a8_a(Gameboy *gb, uint8_t *args) {
  uint16_t addr = 0xFF00 + (uint16_t) args[0]; 
  gb->mem[addr] = gb->A;
  gb->t_state += 12;

  #ifdef DEBUG
  printf("LD [0xFF00+0x%02X],A (A=%02X, *[0xFF00+0x%02X=%02X])\t", args[0], gb->A, args[0], gb->mem[addr]);
  #endif
}

// 0xE2 LD [0xFF00+C],A
void _e2_ld_c_a(Gameboy *gb) {
  uint16_t addr = 0xFF00 + gb->C;
  gb->mem[addr] = gb->A;
  gb->t_state += 8;
  
  #ifdef DEBUG
  printf("LD [0xFF00+C],A (C=%02X, A=%02X, *[0xFF00+C]=%02X)\t", gb->C, gb->A, gb->mem[addr]);
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
