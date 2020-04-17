#include "shell.h"

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
