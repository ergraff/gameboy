// -------- Includes --------
#include <stdint.h>

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

// -------- End of includes --------

// -------- Function prototypes --------
void get_n16(Gameboy *gb, uint8_t *args);
int interpret(Gameboy *gb, uint8_t instr);

// -------- End of function prototypes --------
