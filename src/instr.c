// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

// -------- End of includes --------

// -------- Instructions definitions --------

// 0x31 LD SP,n16
void _31_ld_sp_n16(uint16_t *sp, uint8_t *instr, uint8_t *args) {
  // Form n16 value
  uint16_t a = (uint16_t) args[0];
  uint16_t b = (uint16_t) args[1];
  uint16_t arg = (b << 8) | a;
  
  // Perform instruction
  *sp = arg;

  // Print instruction
  printf("LD SP,%04X (SP=%04X)\t", arg, *sp);
}

// -------- End of instructions definitions --------
