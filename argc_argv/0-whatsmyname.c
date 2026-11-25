#include <stdio.h>

/**
 * main - prints the name of the program, followed by a new line
 * @argc: the number of arguments (unused)
 * @argv: the array of arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
