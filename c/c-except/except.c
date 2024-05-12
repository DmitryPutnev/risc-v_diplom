#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
	asm volatile ("ebreak");

	printf("END!\n");
	return 0;
}
