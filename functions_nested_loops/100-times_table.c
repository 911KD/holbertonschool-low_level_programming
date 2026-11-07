#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the size of the table
 *
 * Description: prints nothing if n is greater than 15 or less than 0
 */
void print_times_table(int n)
{
	int i;
	int j;
	int p;

	if (n < 0 || n > 15)
		return;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			p = i * j;
			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
				if (p < 100)
					_putchar(' ');
				if (p < 10)
					_putchar(' ');
			}
			if (p >= 100)
				_putchar(p / 100 + '0');
			if (p >= 10)
				_putchar(p / 10 % 10 + '0');
			_putchar(p % 10 + '0');
		}
		_putchar('\n');
	}
}
