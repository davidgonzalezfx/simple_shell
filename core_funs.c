#include "shell.h"

/**
 * check_builtin - execute if argv is built-in command
 * @p: struct with all vars
 * Return: int
 */
int check_builtin(params p)
{
	if (_strcmp(p.argv[0], "exit") == 0)
	{
		if (p.argv[1])
		{
			if (check_word(p.argv))
			{
				int status = atoi(p.argv[1]);

				free(p.cmd);
				free(p.buff);
				free(p.argv);
				exit(status);
			}
			else
			{
				char error_msg[64] = "./hsh: ";
				char *cnt = _itoa(*(p.loop));

				_strcat(error_msg, cnt);
				_strcat(error_msg, ": ");
				_strcat(error_msg, p.argv[0]);
				_strcat(error_msg, ": Ilegal number: ");
				_strcat(error_msg, p.argv[1]);
				_strcat(error_msg, "\n");
				free(cnt);
				int error_len = _strlen(error_msg);

				write(2, error_msg, error_len);
				return (1);
			}
		}
		free(p.cmd);
		free(p.buff);
		free(p.argv);
		exit(0);
	}
	return (0);
}

/**
 * not_found_error - hanlder for not found commands
 * @p: struct with all vars
 */
void not_found_error(params p)
{
	char error_msg[64] = "./hsh: ";
	char *cnt = _itoa(*(p.loop));

	_strcat(error_msg, cnt);
	_strcat(error_msg, ": ");
	_strcat(error_msg, p.argv[0]);
	_strcat(error_msg, ": not found\n");
	free(cnt);
	int error_len = _strlen(error_msg);

	write(2, error_msg, error_len);
}

/**
 * non_interactive - handler for non interactive mode
 * @p: struct with all vars
 * Return: void
 */
void non_interactive(params p)
{
	struct stat found;

	if (check_builtin(p) == 1)
		return;
	else if (p.cmd)
	{
		if (fork() == 0)
			execve(p.cmd, p.argv, environ);
		else
		{
			wait(NULL);
			return;
		}
	}
	else if (stat(p.argv[0], &found) == 0)
	{
		if (fork() == 0)

			execve(p.argv[0], p.argv, environ);
		else
		{
			wait(NULL);
			return;
		}
	}
	else
		not_found_error(p);
}

/**
 * simple_exec - core of simple_shell
 * @p: struct with all vars
 */
void simple_exec(params p)
{
	p.cmd = cmd_path(p.argv);
	struct stat found;

	if (isatty(STDIN_FILENO) != 1)
		non_interactive(p);
	else if (check_builtin(p) == 1)
		return;
	else if (stat(p.argv[0], &found) == 0)
	{
		if (fork() == 0)
			execve(p.argv[0], p.argv, environ);
		else
			wait(NULL);
	}
	else if (p.cmd)
	{
		if (fork() == 0)
			execve(p.cmd, p.argv, environ);
		else
			wait(NULL);
	}
	else
		not_found_error(p);
	free(p.cmd);
}
