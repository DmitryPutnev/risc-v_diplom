#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../lib/static_lib.h"

int a = 0;
int b = 5;

// Обработчик прерывания от таймера
void timer_handler() {
	a++;
}


int main() {
	start_timer(10000);
	
	// Бесконечный цикл
	while (a < b)
		printf("a = %d\n", a);

	stop_timer();

	printf("END!\n");
	
	return 0;
}
