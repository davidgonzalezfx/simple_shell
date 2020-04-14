#include "shell.h"
/**
 * _strchr - locates a character in a string
 * @s: char pointer
 * @c: char
 * Return: pointer
 */
char *_strchr(char *s, char c)
{
	int limit;

	for (limit = 0; s[limit]; limit++)
	{
		if (s[limit] == c)
			return (s + limit);
	}
	if (s[limit] == c)
		return (s + limit);
	return (0);
}

/**
 * _strcpy - clone an array
 * @dest: arr of destine
 * @src: arr source
 * Return: dest array
 */
char *_strcpy(char *dest, char *src)
{
	int sizeSrc, el;

	for (sizeSrc = 0; *(src + sizeSrc) != '\0'; sizeSrc++)
	{
	}

	for (el = 0; el <= sizeSrc; el++)
	{
		*(dest + el) = *(src + el);
	}
	return (dest);
}

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: s1 + s2
 */
char *str_concat(char *s1, char *s2)
{
	char *new = NULL;
	int size1, size2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (size1 = 0; s1[size1] != '\0'; size1++)
		;
	for (size2 = 0; s2[size2] != '\0'; size2++)
		;
	new = malloc(sizeof(char) * (size1 + size2) + 1);
	if (!new)
		return (NULL);
	for (i = 0; i < size1; i++)
		*(new + i) = s1[i];
	for (i = size1, j = 0; j < size2; i++, j++)
		new[i] = s2[j];
	new[i] = '\0';
	free(s1);
	return (new);
}
/**
 * _atoi - cast str to int
 * @s: str
 * Return: int
 */
int _atoi(char *s)
{
	int size, aux;
	unsigned int cnt;

	aux = 1;
	cnt = 0;
	for (size = 0; *(s + size) != '\0'; size++)
	{
		if (*(s + size) == '-')
		{
			aux *= -1;
		}
		if (*(s + size) >= '0' && *(s + size) <= '9')
		{
			cnt = (cnt * 10) + (*(s + size) - '0');
			if (!(*(s + size + 1) >= '0' && *(s + size + 1) <= '9'))
				break;
		}
	}
	return (cnt * aux);
}
