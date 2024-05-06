// -------- Includes --------
#include <stdint.h>
#include <stdio.h>

#ifndef INTERPRET_H
#define INTERPRET_H
#include "interpret_cb.h"
#endif

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "instructions.h"
#endif

#define DEBUG

// -------- End of includes --------

// -------- Functions --------
/*
  The function that delegates the current instruction to their individual instructions
*/
int interpret_cb(Gameboy *gb, uint8_t instr) {
  switch (instr) {
    // 0x7C BIT 7,H
    case 0x7C:
      _cb_bit(7, &gb->H, &gb->F, &gb->t_state);
      break;
  }
  return 0;
}

// -------- End of functions --------
