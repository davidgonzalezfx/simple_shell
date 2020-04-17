#include "shell.h"
/**
 * _getenv - search name in environment vars
 * @name: variable to search
 * Return: value of name var - Null if not found
 */
char *_getenv(char *name)
{
	int i, j, var_len;
	char *value;

	var_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] == name[j]; j++)
		{};

		if (environ[i][j] == '=')
		{
			if (var_len == j++)
			{
				for (; environ[i][j]; j++)
				{};

				value = malloc(j - var_len++);
				if (!value)
					return (NULL);

				for (j = 0; environ[i][var_len]; var_len++, j++)
					value[j] = environ[i][var_len];

				value[j] = '\0';
				return (value);
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
	char *dirs;
	char *pth = _getenv("PATH");

	dirs = strtok(pth, ":");

	while (dirs)
	{
		struct stat found;
		char *cmd = malloc(1024);

		_strcpy(cmd, dirs);
		cmd = str_concat(cmd, "/");
		cmd = str_concat(cmd, argv[0]);

		if (stat(cmd, &found) == 0)
			return (free(pth), cmd);
		dirs = strtok(NULL, ":");
		free(cmd);
	}
	free(pth);
	return (NULL);
}
