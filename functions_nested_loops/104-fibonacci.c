#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Description: big numbers are split into two halves to avoid overflow
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long a, b, next;
	unsigned long a1, a2, b1, b2, n1, n2;
	unsigned long split;

	split = 10000000000UL;
	a = 1;
	b = 2;
	printf("%lu, %lu", a, b);
	for (i = 3; i <= 91; i++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}
	a1 = a / split;
	a2 = a % split;
	b1 = b / split;
	b2 = b % split;
	for (i = 92; i <= 98; i++)
	{
		n1 = a1 + b1 + (a2 + b2) / split;
		n2 = (a2 + b2) % split;
		printf(", %lu%010lu", n1, n2);
		a1 = b1;
		a2 = b2;
		b1 = n1;
		b2 = n2;
	}
	printf("\n");
	return (0);
}
