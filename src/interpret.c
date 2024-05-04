// -------- Includes --------
#include <stdint.h>
#include <stdio.h>

#ifndef INTERPRET_H
#define INTERPRET_H
#include "interpret.h"
#endif

#ifndef INTERPRET_CB_H
#define INTERPRET_CB_H
#include "interpret_cb.h"
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
  Helper function to load one byte into args and advance the program counter
*/
void get_e8(Gameboy *gb, uint8_t *args) {
    args[0] = gb->mem[gb->PC];
    gb->PC++;
}

/*
 Helper function to load next byte into args and advance the program counter
*/
void get_cb_instr(Gameboy *gb, uint8_t *args) {
    args[0] = gb->mem[gb->PC];
    gb->PC++;
}

/*
  The function that delegates the current instruction to their individual instructions
*/
int interpret(Gameboy *gb, uint8_t instr) {
  int res = 0;
  uint8_t args[2] = {0};

  switch (instr) {
    // 0x20 JR NZ,e8
    case 0x20:
      get_e8(gb, args);
      _20_jr_nz_e8(gb, args);
      break;

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

    // 0xCB Prefixed operation, interpret separately
    case 0xCB:
      get_cb_instr(gb, args);
      res = interpret_cb(gb, args[0]);
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
