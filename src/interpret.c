// -------- Includes --------
#include <stdint.h>
#include <stdio.h>

#ifndef INTERPRET_H
#define INTERPRET_H
#include "interpret.h"
#endif

#ifndef INSTR_H
#define INSTR_H
#include "instr.h"
#endif

#ifndef GB_H
#define GB_H
#include "gb.h"
#endif

#define DEBUG

// -------- End of includes --------

// -------- Functions --------
/*
  Helper function to load two bytes into args and advance the program counter twice
*/
void get_n16(Gameboy *gb, uint8_t *args) {
    args[0] = gb->mem[gb->PC];
    gb->PC++;
    args[1] = gb->mem[gb->PC];
    gb->PC++;
}

/*
  The function that delegates the current instruction to their individual instructions
*/
int interpret(Gameboy *gb, uint8_t instr) {
  int res = 0;
  uint8_t args[2] = {0};

  switch (instr) {
    // 0x21 LD HL,n16
    case 0x21:
      get_n16(gb, args);
      _21_ld_hl_n16(gb, args);
      break;

    // 0x31 LD SP,n16
    case 0x31:
      get_n16(gb, args);
      _31_ld_sp_n16(gb, args);
      break;

    // 0x32 LD [HL-],A
    case 0x32:
      _32_ld_hld_a(gb);
      break;

    // 0xAF XOR A
    case 0xAF:
      _af_xor_a(gb);
      break;

    // Default case, the instruction has not been defined.
    default:
      res = 1;
      break;
  }

  #ifdef DEBUG
  // Print instruction and arguments
  printf("%02X ", instr);
  for (int i = 0; i < 2; i++) {
    int a = args[i];
    if (a > 0) {
      printf("%02X ", a);
    }
  }
  printf("\n");
  #endif


  return res;
}

// -------- End of functions --------
