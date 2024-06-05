#include "sw_interrupt_lib.h"
#include "../../bsp/encoding.h"

/**
* @brief Вызывает программное прерывание
*/
void enable_software_interrupt() {
	asm volatile (
		"mv t0, %0\n"
		"csrw mip, t0\n"
		"mv t0, %1\n"
		"csrw mie, t0\n"
		:: "r" (1 << 1), "r" (1 << 1)
	);
}

/**
* @brief Выключает программное прерывание
*/
void disable_software_interrupt() {
	asm volatile (
		"csrwi mie, 0\n"
		"csrwi mip, 0\n"
	);
}
