#include "cpu.c"

// -------- CPU prototype --------
struct CPU;

// -------- End of CPU prototype --------

// -------- Instructions prototypes --------
void nop();

void ld();
void ldh();

void ld_hl();
void ld_sp();

void add();
void adc();
void sub();
void sbc();

void inc();
void dec();

void and();
void or();
void xor();

void cp();
void cpl();

void rla();
void rlca();

void rra();
void rrca();

void daa();

void scf();

void ccf();

void stop();
void halt();

void jr();
void jp();

void call();
void ret();

void push();
void pop();

void rst();

// -------- End of instructions prototypes --------
