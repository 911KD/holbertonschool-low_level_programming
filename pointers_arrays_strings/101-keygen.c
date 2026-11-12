#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Description: builds a string whose ASCII values sum to TARGET,
 * using only printable characters (33 to 126)
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int target;
	int sum;
	int remaining;
	int c;
	int max_c;
	int i;
	char pass[200];

	target = 2772;
	sum = 0;
	i = 0;
	srand(time(NULL));
	while (sum != target)
	{
		remaining = target - sum;
		if (remaining <= 126)
		{
			c = remaining;
		}
		else
		{
			max_c = remaining - 33;
			if (max_c > 126)
				max_c = 126;
			c = (rand() % (max_c - 33 + 1)) + 33;
		}
		pass[i] = c;
		sum += c;
		i++;
	}
	pass[i] = '\0';
	printf("%s", pass);
	return (0);
}
