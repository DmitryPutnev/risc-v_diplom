#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uintptr_t handle_trap(uintptr_t cause, uintptr_t epc, uintptr_t regs[32]) {
	printf("interrupt\n");
	
	exit(1);
}

int main() {
	asm volatile ("unimp");

	printf("END!\n");
	return 0;
}
