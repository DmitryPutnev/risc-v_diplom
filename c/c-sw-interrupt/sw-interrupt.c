#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../lib/static_lib.h"

int a = 0;

void sw_interrupt_handler() {
	a = 100;
	disable_software_interrupt();
}

int main() {
	enable_software_interrupt();
	
	if (a == 100)
		printf("Success!\n");
	else
		printf("Fail!\n");
		
	return 0;
}
