// -------- Includes --------
#ifndef STDINT_H
#define STDINT_H
#include <stdint.h>
#endif

#include "gb.c"

// -------- End of includes --------

// -------- Gameboy prototype --------
struct Gameboy;

// -------- End of Gameboy prototype --------

// -------- Function prototypes --------
Gameboy gameboy_initialize();
void load_dmg_rom(Gameboy *gb);

// -------- End of function prototypes --------
