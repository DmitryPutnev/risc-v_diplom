#include "timer_lib.h"
#include "../../bsp/encoding.h"

/**
* @brief Инициализирует период прерывание
* @param time Период прерывания
*/
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

/**
* @brief Включает прерывание от таймера
*/
void enable_timer() {
	asm volatile (
		"mv t0, %0\n"
		"csrw mie, t0\n"
		:: "r" (1 << 7)
	);
}

/**
* @brief Выключает прерывание от таймера
*/
void disable_timer() {
	asm volatile ("csrwi mie, 0");
}

/**
* @brief Сбрасывает счетчик таймера
*/
void reset_timer() {
	asm volatile (
		"mv t0, %0\n"
		"sw zero, 0(t0)\n"
		"sw zero, 4(t0)\n"
		:: "r" (ADDR_MTIME)
	);
}

