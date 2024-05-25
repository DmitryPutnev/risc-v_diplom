#include "sys_lib.h"

void start_timer(int time) {
	asm volatile (
		"mv a7, %0\n"
		"mv a0, %1\n"
		"ecall\n"
		:: "r" (SYS_start_timer), "r" (time)
	);
}

void stop_timer(int time) {
	asm volatile (
		"mv a7, %0\n"
		"ecall\n"
		:: "r" (SYS_stop_timer)
	);
}

void start_sw_interrupt() {
	asm volatile (
		"mv a7, %0\n"
		"ecall\n"
		:: "r" (SYS_start_sw_interrupt)
	);
}
