#include "timer_lib.h"
#include "../../bsp/encoding.h"

void init_timer(int time) {
	asm volatile (
		"mv t0, %0\n"
		"sw zero, 0(t0)\n"
		"sw zero, 4(t0)\n"
		
		"mv t1, %1\n"
		"mv t0, %2\n"
		"sw t1, 0(t0)\n"
		"sw zero, 4(t0)\n"
		:: "r" (ADDR_MTIME), "r" (time), "r" (ADDR_MTIMECMP)
	);
}

void enable_timer() {
	asm volatile (
		"mv t0, %0\n"
		"csrw mie, t0\n"
		:: "r" (1 << 7)
	);
}

void disable_timer() {
	asm volatile ("csrwi mie, 0");
}

void reset_timer() {
	asm volatile (
		"mv t0, %0\n"
		"sw zero, 0(t0)\n"
		"sw zero, 4(t0)\n"
		:: "r" (ADDR_MTIME)
	);
}

