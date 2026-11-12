#include <stdio.h>
#include "main.h"

/**
 * print_array - prints n elements of an array of integers
 * @a: the array of integers
 * @n: the number of elements to print
 *
 * Description: numbers are separated by a comma and a space,
 * followed by a new line
 */
void print_array(int *a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (i != 0)
			printf(", ");
		printf("%d", a[i]);
		i++;
	}
	printf("\n");
}
