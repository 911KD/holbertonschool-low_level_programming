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
		if (choice < 0 || choice > 4)
			printf("Invalid choice\n");
	}
	printf("Bye!\n");
	return (0);
}
