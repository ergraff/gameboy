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

// -------- Instructions definitions --------

// 0x21 LD HL,n16
void _21_ld_hl_n16(Gameboy *gb, uint8_t *args) {
  uint8_t low = args[0];
  uint8_t high = args[1];
  gb->H = high;
  gb->L = low;

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

  #ifdef DEBUG
  printf("LD [HL-],A (*[HL]=%02X, HL:%04X->%04X, H=%02X, L=%02X)\t", gb->mem[addr], addr, addr_new, gb->H, gb->L);
  #endif  
}

// 0xAF XOR A
void _af_xor_a(Gameboy *gb) {
  gb->A = gb->A ^ gb->A; 

  #ifdef DEBUG
  printf("XOR A (A=%02X)\t", gb->A);
  #endif
}

// -------- End of instructions definitions --------
