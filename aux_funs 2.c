#include "shell.h"

 /**
 * _strdup - create an array with the an specified number
 * @str: string to copy
 * Return: 0 if something fails or size is 0, and a pointer to the copy
 */
char *_strdup(char *str)
{
	char *scp;
	unsigned int size, i;

	if (!str)
		return (NULL);
	size = _strlen(str);
	scp = malloc(size * sizeof(char) + 1);
	if (!scp)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		scp[i] = str[i];
		i++;
	}
	return (scp);
}

char *get_cp_path(char *path)
{
	char *cp;

	cp  = _strdup(path);
	return(cp);
}