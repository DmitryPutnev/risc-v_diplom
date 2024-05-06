#include <stdio.h>

int main()
{
	int a = 5, b = 6, sum;
	
	asm volatile (
		"add %0, %1, %2"
		: "=r" (sum)
		: "r" (a), "r" (b)
	);

  	printf("Sum = %d\n", sum);

  	return 0;
}
