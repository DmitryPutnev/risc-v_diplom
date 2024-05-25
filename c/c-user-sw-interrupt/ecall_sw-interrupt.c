#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../bsp/user/sys_lib.h"

int a = 0;

void sw_interrupt_handler() {
	a = 100;
}

int main() {
	start_sw_interrupt();
	
	if (a == 100)
		printf("Success!\n");
	else
		printf("Fail!\n");
		
	return 0;
}
