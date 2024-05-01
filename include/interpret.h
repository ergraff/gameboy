// -------- Includes --------
#include <stdint.h>

#ifndef GB_H
#define GB_H
#include "gb.h"
#endif

// -------- End of includes --------

// -------- Function prototypes --------
void get_n16(Gameboy *gb, uint8_t *args);
int interpret(Gameboy *gb, uint8_t instr);

// -------- End of function prototypes --------
