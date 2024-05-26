#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../lib/static_lib.h"

int a = 0;
int b = 5;

// Обработчик прерывания от таймера
void timer_handler() {
	a++;
	reset_timer();
}


int main() {
	// Установка периода прерывания таймера
	init_timer(0x18000);

	// Включение прерываний таймера
	enable_timer();

	// Бесконечный цикл
	while (a < b)
		printf("a = %d\n", a);
		
		disable_timer();
	// Выключение прерываний таймера
	printf("END!\n");
	
	return 0;
}
