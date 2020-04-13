#include "shell.h"

/**
 * check_word - evalute alpha chars in string
 * @argv: arguments
 * Return: 1 if no alpha chars, 0 if yes
 */
int check_word(char **argv)
{
	int i;

	for (i = 0; i < _strlen(argv[1]); i++)
		if (!isdigit(argv[1][i]))
			return (0);
	return (1);
}
