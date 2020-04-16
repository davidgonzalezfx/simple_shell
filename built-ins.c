#include "shell.h"

/**
 * _isdigit - check for digit
 * @c: int
 * Return: int
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * check_word - evalute alpha chars in string
 * @argv: arguments
 * Return: 1 if no alpha chars, 0 if yes
 */
int check_word(char **argv)
{
	int i;

	for (i = 0; i < _strlen(argv[1]); i++)
		if (!_isdigit(argv[1][i]))
			return (0);
	return (1);
}

/**
 * exit_built_in - Handler of exit built-in command
 * Description: exit stop the shell, exit(status)
 * stops and 'return' status
 * @p: struct with all vars inside
 * Return: 1 if no alpha chars
 */
int exit_built_in(params *p)
{
	if (p->argv[1])
	{
		if (check_word(p->argv))
		{
			int status = _atoi(p->argv[1]);

			free(p->cmd);
			free(p->buff);
			free(p->argv);
			exit(status);
		}
		else
		{
			int error_len;
			char error_msg[64] = "";
			char *cnt = _itoa(*(p->loop));

			_strcpy(error_msg, p->name);
			_strcat(error_msg, ": ");
			_strcat(error_msg, cnt);
			_strcat(error_msg, ": ");
			_strcat(error_msg, p->argv[0]);
			_strcat(error_msg, ": Illegal number: ");
			_strcat(error_msg, p->argv[1]);
			_strcat(error_msg, "\n");
			free(cnt);

			error_len = _strlen(error_msg);

			write(2, error_msg, error_len);
			p->exit_value = 2;
			return (1);
		}
	}
	free(p->cmd);
	free(p->buff);
	free(p->argv);
	exit(p->exit_value);
}

/**
 * env_built_in - Handler of exit built-in command
 * @p: struct with all vars
 */
void env_built_in(params *p)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	free(p->cmd);
}
