#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "/home/dmitry/Документы/riscv-programm-diplom/bsp/encoding.h"
#include "/home/dmitry/Документы/riscv-programm-diplom/lib/timer/timer_lib.h"

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
	// Установка периода прерывания таймера
	init_timer(0x18000);

	// Включение прерываний таймера
	enable_timer_interrupt();

	
	// Бесконечный цикл
	while (a < b) {
		printf("a = %d\n", a);
		asm volatile ("wfi");
	}

	printf("END!\n");
	return 0;
}
