#include "sys_lib.h"

void set_timer(int time) {
	asm volatile (
		"mv a7, %0\n"
		"mv a0, %1\n"
		"ecall\n"
		:: "r" (SYS_start_timer), "r" (time)
	);
}

