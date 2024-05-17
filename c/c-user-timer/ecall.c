#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../lib/timer/timer_lib.h"
#include "../../bsp/user/sys_lib.h"

int a = 0;
int b = 5;

// Обработчик прерывания от таймера
uintptr_t timer_handler(uintptr_t cause, uintptr_t epc, uintptr_t regs[32]) {
	printf("Interrupt = %d\n", cause);
	a++;
	
	reset_timer();
	return epc;
}


int main() {
	set_timer(0X18000);
	
	// Бесконечный цикл
	while (a < b) {
		printf("a = %d\n", a);
		asm volatile ("wfi");
	}

	printf("END!\n");
	return 0;
}
