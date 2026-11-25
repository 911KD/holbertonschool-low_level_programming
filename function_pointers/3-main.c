#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs a simple operation on two numbers
 * @argc: the number of arguments
 * @argv: the arguments: num1 operator num2
 *
 * Return: 0 on success, exits with 98, 99 or 100 on error
 */
int main(int argc, char *argv[])
{
	int (*f)(int, int);
	int a, b;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	f = get_op_func(argv[2]);
	if (f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", f(a, b));
	return (0);
}
