#include "shell.h"
/**
 * _strcmp - compare two strings
 * @s1: char*
 * @s2: char*
 * Return: int -1, 1, 0
 */
int _strcmp(char *s1, char *s2)
{
	int i, size1, size2;

	for (size1 = 0; *(s1 + size1) != '\0'; size1++)
	{
	}
	for (size2 = 0; *(s2 + size2) != '\0'; size2++)
	{
	}
	size1--;
	size2--;
	for (i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
/**
 * signal_exit - handling CTRL +
 * @a: unneeded param
 */
void signal_exit(int a)
{
	(void) a;
	write(1, "\nhsh$ ", 6);
}
/**
 * _calloc - allocates memory for an array
 * @nmemb: # elements
 * @size: size of elements
 * Return: void, just allocate memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem;
	unsigned int index = 0;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	for (; index < (nmemb * size); index++)
		*(mem + index) = 0;
	return (mem);
}
