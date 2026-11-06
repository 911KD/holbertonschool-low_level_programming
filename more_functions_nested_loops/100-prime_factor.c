#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long n;
	unsigned long i;

	n = 612852475143UL;
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			n = n / i;
		else
			i++;
	}
	printf("%lu\n", n);
	return (0);
}
