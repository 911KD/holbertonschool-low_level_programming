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
 * read_number - prints a label and reads a decimal number
 * @label: the prompt to print (e.g. "A: ")
 * @n: where to store the number
 *
 * Return: 1 on success, 0 if the input was not a number
 */
int read_number(const char *label, double *n)
{
	printf("%s", label);
	if (scanf("%lf", n) != 1)
	{
		clear_input();
		printf("Invalid input\n");
		return (0);
	}
	return (1);
}

/**
 * print_result - prints a result without useless trailing zeros
 * @r: the value to print
 *
 * Return: nothing
 */
void print_result(double r)
{
	if (r == 0)
		r = 0;
	printf("Result: %.15g\n", r);
}

/**
 * calculate - reads A and B and applies the chosen operation
 * @choice: 1 add, 2 subtract, 3 multiply, 4 divide
 *
 * Return: nothing
 */
void calculate(int choice)
{
	double a, b;

	if (!read_number("A: ", &a) || !read_number("B: ", &b))
		return;
	if (choice == 1)
		print_result(a + b);
	else if (choice == 2)
		print_result(a - b);
	else if (choice == 3)
		print_result(a * b);
	else if (b == 0)
		printf("Error: division by zero\n");
	else
		print_result(a / b);
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
		if (choice >= 1 && choice <= 4)
			calculate(choice);
		else
			printf("Invalid choice\n");
	}
	printf("Bye!\n");
	return (0);
}
