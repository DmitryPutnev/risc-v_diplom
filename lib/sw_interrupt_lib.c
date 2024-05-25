#include "sw_interrupt_lib.h"
#include "../bsp/encoding.h"

void enable_software_interrupt() {
	asm volatile (
		"csrr t0, mstatus\n"
		"add t0, t0, %0\n"
		"csrw mstatus, t0\n"
		"mv t0, %1\n"
		"csrw mip, t0\n"
		"mv t0, %2\n"
		"csrw mie, t0\n"
		:: "r" (MSTATUS_MIE), "r" (1 << 1), "r" (1 << 1)
	);
}

void disable_software_interrupt() {
	asm volatile (
		"csrwi mie, 0\n"
		"csrwi mie, 0\n"
	);
}
