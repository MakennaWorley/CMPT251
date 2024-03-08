/* * io.c * * A demonstration of simple I/O in C (printf and scanf) */
#include <stdio.h>

int main()
{
	int age;
	printf("How old are you? ");
	scanf("%d", &age);

	printf("That means next year you'll be %d! Can you believe it?\n", age + 1);
	printf("That means you were probably born in %d!\n", 2023-age);

	return 0;
}
