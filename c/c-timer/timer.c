#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "/home/dmitry/Документы/riscv-programm-diplom/bsp/encoding.h"


#define ADDR_MTIMECMP 0x02004000
#define ADDR_MTIME 0x0200bff8

int a = 0;
int b = 5;

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
		:: "r" (MSTATUS_MIE), "r" (1 << 7)
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

// Обработчик прерывания от таймера
uintptr_t handle_trap(uintptr_t cause, uintptr_t epc, uintptr_t regs[32]) {
	printf("Interrupt!\n");
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
	}

	printf("END!\n");
	return 0;
}
