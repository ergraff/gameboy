// -------- Includes --------
#include <stdint.h>

// -------- End of includes --------

// -------- Gameboy prototype --------
typedef struct Gameboy Gameboy;

// -------- End of Gameboy prototype --------

// -------- Function prototypes --------
Gameboy *initialize();
int load_dmg_rom(Gameboy *gb);
uint8_t current_instruction(Gameboy *gb);
int perform_instruction(Gameboy *gb);
int run(Gameboy *gb);

// -------- End of function prototypes --------
