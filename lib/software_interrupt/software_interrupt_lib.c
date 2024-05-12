#include "software_interrupt_lib.h"
#include "/home/dmitry/Документы/riscv-programm-diplom/bsp/encoding.h"

void enable_software_interrupt() {
	asm volatile (
		"mv t0, %0\n"
		"csrw mstatus, t0\n"
		"mv t0, %1\n"
		"csrw mip, t0\n"
		"mv t0, %2\n"
		"csrw mie, t0\n"
		:: "r" (MSTATUS_MIE), "r" ((1 << 1) + (1 << 3)), "r" ((1 << 1) + (1 << 3))
	);
}

