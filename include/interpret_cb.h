// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#ifndef GAMEBOY_H
#define GAMEBOY_H
#include "gameboy.h"
#endif

// -------- End of includes --------

// -------- Function prototypes --------
int interpret_cb(Gameboy *gb, uint8_t instr);

// -------- End of function prototypes --------
