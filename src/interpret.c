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
void load_two_byte(Gameboy *gb, uint8_t *args) {
    args[0] = gb->mem[gb->PC];
    gb->PC++;
    args[1] = gb->mem[gb->PC];
    gb->PC++;
}

/*
  Helper function to load one byte into args and advance the program counter
*/
void load_one_byte(Gameboy *gb, uint8_t *args) {
    args[0] = gb->mem[gb->PC];
    gb->PC++;
}

/*
 Helper function to load next byte into args and advance the program counter
*/
void load_cb_instr(Gameboy *gb, uint8_t *args) {
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
    // 0x0C INC C
    case 0x0C:
      _0c_inc_c(gb);
      break;

    // 0x0E JR NZ,e8
    case 0x0E:
      load_one_byte(gb, args);
      _0e_ld_c_n8(gb, args);
      break;

    // 0x11 LD DE,n16
    case 0x11:
      load_two_byte(gb, args);
      _11_ld_de_n16(gb, args);
      break;

    // 0x1A LD A,[DE]
    case 0x1A:
      _1a_ld_a_de(gb);
      break;
      
    // 0x20 JR NZ,e8
    case 0x20:
      load_one_byte(gb, args);
      _20_jr_nz_e8(gb, args);
      break;

    // 0x21 LD HL,n16
    case 0x21:
      load_two_byte(gb, args);
      _21_ld_hl_n16(gb, args);
      break;

    // 0x31 LD SP,n16
    case 0x31:
      load_two_byte(gb, args);
      _31_ld_sp_n16(gb, args);
      break;

    // 0x32 LD [HL-],A
    case 0x32:
      _32_ld_hld_a(gb);
      break;

    // 0x3E LD A,n8
    case 0x3E:
      load_one_byte(gb, args);
      _3e_ld_a_n8(gb, args);
      break;

    // 0x77 LD [HL],A
    case 0x77:
      _77_ld_hl_a(gb);
      break;

    // 0xAF XOR A
    case 0xAF:
      _af_xor_a(gb);
      break;

    // 0xCB Prefixed operation, interpret separately
    case 0xCB:
      load_cb_instr(gb, args);
      res = interpret_cb(gb, args[0]);
      break;

    // 0xCD CALL a16
    case 0xCD:
      load_two_byte(gb, args);
      res =_cd_call_a16(gb, args);
      break;

    // 0xE0 LDH [0xFF00+a8],A
    case 0xE0:
      load_one_byte(gb, args);
      _e0_ld_a8_a(gb, args);
      break;

    // 0xE2 LD [0xFF00+C],A
    case 0xE2:
      _e2_ld_c_a(gb);
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
