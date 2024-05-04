// -------- Includes --------
#include <stdint.h>

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

// -------- End of includes --------

// -------- Function prototypes --------
void load_two_byte(Gameboy *gb, uint8_t *args);
void load_one_byte(Gameboy *gb, uint8_t *args);
void load_cb_instr(Gameboy *gb, uint8_t *args);
int interpret(Gameboy *gb, uint8_t instr);

// -------- End of function prototypes --------
