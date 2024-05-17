#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../bsp/encoding.h"
#include "../../lib/software_interrupt/software_interrupt_lib.h"

int main() {
	enable_software_interrupt();

	/*asm volatile (
		"li a7, 0\n"
		"ecall"
	);*/

	printf("END!\n");
	return 0;
}
