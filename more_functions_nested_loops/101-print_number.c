#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 */
void print_number(int n)
{
	unsigned int num;
	unsigned int div;

	if (n < 0)
	{
		_putchar('-');
		num = -(unsigned int)n;
	}
	else
	{
		num = n;
	}
	div = 1;
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		_putchar(num / div % 10 + '0');
		div /= 10;
	}
}
