#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 on success, 1 if the program does not receive two arguments
 */
int main(int argc, char *argv[])
{
	int a, b;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("%d\n", a * b);

	return (0);
}
