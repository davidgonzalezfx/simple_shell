#include "shell.h"
/**
 * _strcat - append src to dest
 * @dest: first string
 * @src: string to be appended
 * Return: final dest string
 */
char *_strcat(char *dest, char *src)
{
	int i;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (i = i; *src; i++)
	{
		*(dest + i) = *src++;
	}
	return (dest);
}
/**
 * _strlen - return length of string
 * @s: char
 * Return: int
 */
int _strlen(char *s)
{
	int cnt;

	for (cnt = 0; *(s + cnt) != '\0'; cnt++)
	{
	}
	return (cnt);
}
/**
 * rev_string - reverse_string
 * Description: Tool for convert int to string
 * @s: string
 * Return: void
 */
void rev_string(char *s)
{
	int init, end;
	char aux;

	for (end = 0; *(s + end) != '\0'; end++)
	{
	};
	end--;
	for (init = 0; init < end; init++)
	{
		aux = *(s + init);
		*(s + init) = *(s + end);
		*(s + end--) = aux;
	}
}
/**
 * _itoa - convert num to base 10 and return in string
 * @num: int
 * Return: string
 */
char *_itoa(unsigned int num)
{
	char *tool = "0123456789abcdef";
	char *new = _calloc(64, 1), *init;

	if (!new)
		return (NULL);
	init = new;
	while (num != 0)
	{
		*new++ = tool[num % 10];
		num /= 10;
	}
	rev_string(init);
	return (init);
}

/**
 * _strcmp - compare two strings
 * @s1: char*
 * @s2: char*
 * Return: int -1, 1, 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
		if (s1[i] != s2[i])
			return (-1);
	return (0);
}
