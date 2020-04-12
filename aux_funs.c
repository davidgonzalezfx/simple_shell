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
 *_strlength - calulate the length of a string
 *@p: string to messure
 *Return: length of the string
 */
unsigned int _strlength(const char *p)
{
	return ((!*p) ? (0) : (1 + (_strlength(++p))));
}

/**
 * str_concat - create an array with the an specified number
 * @s1: string to concatenate
 * @s2: string to concatenate
 * Return: 0 if something fails or size is 0,
 * and a pointer to the concatened string
 */
char *str_concat(const char *s1, const char *s2)
{
	char *scp;
	unsigned int i;

	scp = NULL;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	scp = malloc((_strlength(s1) * sizeof(char)) +
			 (_strlength(s2) * sizeof(char)) + 1);
	if (!scp)
		return (NULL);
	i = 0;
	while (*s1)
	{
		*scp = *s1;
		s1++, scp++, i++;
	}
	while (*s2)
	{
		*scp = *s2;
		s2++, scp++, i++;
	}
	*scp = '\0';
	scp -= i;
	return (scp);
}

/**
 * free_list - frees a linked list
 * @head: the head of the string
 * Return: nothing
 */
void free_list(node_path_t *head)
{
	node_path_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->path);
		free(temp);
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
