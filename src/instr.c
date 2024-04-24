// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

// -------- End of includes --------

// -------- Instructions definitions --------

// 0x21 LD HL,n16
void _21_ld_hl_n16(uint8_t *h, uint8_t *l, uint8_t *args) {
  uint8_t low = args[0];
  uint8_t high = args[1];
  *h = high;
  *l = low;

  #ifdef DEBUG
  printf("LD HL,%02X%02X (HL=%02X%02X)\t", high, low, *h, *l);
  #endif
}

// 0x31 LD SP,n16
void _31_ld_sp_n16(uint16_t *sp, uint8_t *args) {
  uint16_t a = (uint16_t) args[0];
  uint16_t b = (uint16_t) args[1];
  uint16_t arg = (b << 8) | a;
  *sp = arg;

  #ifdef DEBUG
  printf("LD SP,%04X (SP=%04X)\t", arg, *sp);
  #endif
}

// 0x32 LD [HL-],A
void _32_ld_hld_a(uint8_t *mem, uint8_t *h, uint8_t *l, uint8_t *a) {
  uint16_t low = (uint16_t) *l;
  uint16_t high = (uint16_t) *h;
  uint16_t addr = (high << 8) | low;
  mem[addr] = *a;

  uint16_t addr_new = addr - 1;
  uint8_t low_new = (uint8_t) addr_new;
  uint8_t high_new = (uint8_t) (addr_new >> 8);
  *h = high_new;
  *l = low_new;

  #ifdef DEBUG
  printf("LD [HL-],A (*[HL]=%02X, HL:%04X->%04X, H=%02X, L=%02X)\t", mem[addr], addr, addr_new, *h, *l);
  #endif  
}

// 0xAF XOR A
void _af_xor_a(uint8_t *a) {
  *a = *a ^ *a; 

  #ifdef DEBUG
  printf("XOR A (A=%02X)\t", *a);
  #endif
}

// -------- End of instructions definitions --------
