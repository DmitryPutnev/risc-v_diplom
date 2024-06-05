#include "sys_lib.h"

/**
* @brief Инициализирует период прерывани и включает прерывания от таймера
* @param time Период прерывания
*/
void start_timer(int time) {
	asm volatile (
		"mv a7, %0\n"
		"mv a0, %1\n"
		"ecall\n"
		:: "r" (SYS_start_timer), "r" (time)
	);
}

/**
* @brief Выключает прерывание от таймера
*/
void stop_timer() {
	asm volatile (
		"mv a7, %0\n"
		"ecall\n"
		:: "r" (SYS_stop_timer)
	);
}

/**
* @brief Вызывает программное прерывание
*/
void start_sw_interrupt() {
	asm volatile (
		"mv a7, %0\n"
		"ecall\n"
		:: "r" (SYS_start_sw_interrupt)
	);
}
