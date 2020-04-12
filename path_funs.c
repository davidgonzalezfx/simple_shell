#include "shell.h"
/**
 * _getenv - search name in environment vars
 * @name: variable to search
 * Return: value of name var - Null if not found
 */
char *_getenv(const char *name)
{
	int i, j, size;
	char *res;

	size = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] == name[j]; j++)
			;
		if (environ[i][j] == '=')
		{
			if (size == j++)
			{
				for (; environ[i][j]; j++)
					;
				res = malloc(sizeof(char) * (j - size));
				if (!res)
					return (NULL);
				size++;
				for (j = 0; environ[i][size]; size++, j++)
					res[j] = environ[i][size];
				res[j] = '\0';
				return (res);
			}
		}
	}

	return (NULL);
}
/**
 * cmd_path - concat argument with PATH dirs
 * @argv: argument to concat
 * Return: absoulte path of command - Null if doesn't exits
 */
char *cmd_path(char **argv)
{
	char *pth = _getenv("PATH");
	char *dirs = strtok(pth, ":");

	while (dirs)
	{
		struct stat found;
		char *cmd = malloc(1024);

		strcpy(cmd, dirs);
		strcat(cmd, "/");
		strcat(cmd, argv[0]);
		
		if (stat(cmd, &found) == 0)
			return (free(pth), cmd);
		dirs = strtok(NULL, ":");
		free(cmd);
	}
	free(pth);
	return (NULL);
}
