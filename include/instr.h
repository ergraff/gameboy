// -------- Includes --------
#include <stdint.h>
#include "gb.h"

// -------- End of includes --------

// -------- Instructions prototypes --------
// 0x21 LD HL,n16
void _21_ld_hl_n16(uint8_t *h, uint8_t *l, uint8_t *args);

// 0x31 LD SP,n16
void _31_ld_sp_n16(uint16_t *sp, uint8_t *args);

// 0x32 LD [HL-],A
void _32_ld_hld_a(uint8_t *mem, uint8_t *h, uint8_t *l, uint8_t *a);

// 0xAF XOR A
void _af_xor_a(uint8_t *a);

// -------- End of instructions prototypes --------
