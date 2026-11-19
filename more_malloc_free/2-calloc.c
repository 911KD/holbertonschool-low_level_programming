#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates zeroed memory for an array using malloc
 * @nmemb: the number of elements
 * @size: the size of each element in bytes
 *
 * Return: pointer to the allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int total, i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);

	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		ptr[i] = 0;

	return (ptr);
}
