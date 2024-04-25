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
uint8_t get_pc_val(Gameboy *gb);
void get_n16(Gameboy *gb, uint8_t *args);
int perform_instruction(Gameboy *gb);
int run(Gameboy *gb);

// -------- End of function prototypes --------
