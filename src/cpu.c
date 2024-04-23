// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

// -------- End of includes --------

// -------- CPU definitions --------
typedef struct CPU {
  /*
    Cycle counter
  */
  uint32_t cycle;
  
  /*
    Registers
  */
  uint8_t A;
  uint8_t B;
  uint8_t C;
  uint8_t D;
  uint8_t E;
  uint8_t F;
  uint8_t H;
  uint8_t L;

  /*
    Pointers
  */
  uint16_t SP;
  uint16_t PC;
  
} CPU;

// -------- Functions --------
CPU cpu_initialize() {
  CPU cpu = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  return cpu;
}

// -------- End of functions --------

// -------- Instructions definitions --------
void nop() {}

void ld() {}
void ldh() {}

void ld_hl() {}
void ld_sp() {}

void add() {}
void adc() {}
void sub() {}
void sbc() {}

void inc() {}
void dec() {}

void and() {}
void or() {}
void xor() {}

void cp() {}
void cpl() {}

void rla() {}
void rlca() {}

void rra() {}
void rrca() {}

void daa() {}

void scf() {}

void ccf() {}

void stop() {}
void halt() {}

void jr() {}
void jp() {}

void call() {}
void ret() {}

void push() {}
void pop() {}

void rst() {}

// -------- End of instructions definitions --------
