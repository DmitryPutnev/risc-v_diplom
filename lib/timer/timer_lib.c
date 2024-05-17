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

void enable_timer_interrupt() {
	asm volatile (
		"mv t0, %0\n"
		"csrw mstatus, t0\n"
		"mv t0, %1\n"
		"csrw mie, t0\n"
		"mv t0, %2\n"
		"csrw mip, t0\n"
		"mv t0, %3\n"
		"csrw mideleg, t0\n"
		"mv t0, %4\n"
		"csrw medeleg, t0\n"
		:: "r" (MSTATUS_MIE + MSTATUS_SIE + MSTATUS_UIE), "r" ((1 << 7) + (1 << 5)), "r" ((1 << 7) + (1 << 5)), "r" ((1 << 7) + (1 << 5)), "r" ((1 << 7) + (1 << 5))
	);
}

void reset_timer() {
	asm volatile (
		"mv t0, %0\n"
		"sw zero, 0(t0)\n"
		"sw zero, 4(t0)\n"
		:: "r" (ADDR_MTIME)
	);
}

