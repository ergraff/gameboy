// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

// -------- End of includes --------

// -------- Instructions definitions --------

// 0x21 LD HL,n16
void _21_ld_hl_n16(uint8_t *h, uint8_t *l, uint8_t *args) {
  // Get values
  uint8_t low = args[0];
  uint8_t high = args[1];

  // Perform operation
  *h = high;
  *l = low;

  #ifdef DEBUG
  // Print instruction
  printf("LD HL,%02X%02X (HL=%02X%02X)\t", high, low, *h, *l);
  #endif
}

// 0x31 LD SP,n16
void _31_ld_sp_n16(uint16_t *sp, uint8_t *args) {
  // Form n16 value, Big Endian to Small Endian
  uint16_t a = (uint16_t) args[0];
  uint16_t b = (uint16_t) args[1];
  uint16_t arg = (b << 8) | a;
  
  // Perform instruction
  *sp = arg;

  #ifdef DEBUG
  // Print instruction
  printf("LD SP,%04X (SP=%04X)\t", arg, *sp);
  #endif
}

// 0xAF XOR A
void _af_xor_a(uint8_t *a) {
  *a = *a ^ *a; 

  #ifdef DEBUG
  // Print instruction
  printf("XOR A (A=%02X)\t", *a);
  #endif
}

// -------- End of instructions definitions --------
