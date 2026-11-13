#include <stdio.h>

/**
 * print_menu - prints the calculator menu and the choice prompt
 *
 * Return: nothing
 */
void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");
}

/**
 * clear_input - discards the rest of the current input line
 *
 * Return: nothing
 */
void clear_input(void)
{
	int c;

	c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
}

/**
 * read_number - prints a label and reads an integer
 * @label: the prompt to print (e.g. "A: ")
 * @n: where to store the number
 *
 * Return: 1 on success, 0 if the input was not a number
 */
int read_number(const char *label, int *n)
{
	printf("%s", label);
	if (scanf("%d", n) != 1)
	{
		clear_input();
		printf("Invalid input\n");
		return (0);
	}
	return (1);
}

/**
 * do_add - reads A and B and prints their sum
 *
 * Return: nothing
 */
void do_add(void)
{
	int a, b;

	if (!read_number("A: ", &a) || !read_number("B: ", &b))
		return;
	printf("Result: %d\n", a + b);
}

/**
 * do_sub - reads A and B and prints A - B
 *
 * Return: nothing
 */
void do_sub(void)
{
	int a, b;

	if (!read_number("A: ", &a) || !read_number("B: ", &b))
		return;
	printf("Result: %d\n", a - b);
}

/**
 * main - entry point of the simple calculator
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int choice;
	int ret;

	printf("Simple Calculator\n");
	while (1)
	{
		print_menu();
		ret = scanf("%d", &choice);
		if (ret == EOF || (ret == 1 && choice == 0))
			break;
		if (ret != 1)
		{
			clear_input();
			printf("Invalid choice\n");
			continue;
		}
		if (choice == 1)
			do_add();
		else if (choice == 2)
			do_sub();
		else if (choice < 0 || choice > 4)
			printf("Invalid choice\n");
	}
	printf("Bye!\n");
	return (0);
}
