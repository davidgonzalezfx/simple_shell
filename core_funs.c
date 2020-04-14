#include "shell.h"

/**
 * check_builtin - execute if argv is built-in command
 * @p: struct with all vars
 * Return: int
 */
int check_builtin(params p)
{
	if (_strcmp(p.argv[0], "exit") == 0)
		return (exit_built_in(p));
	else if (_strcmp(p.argv[0], "env") == 0)
		return (env_built_in(), 1);
	return (0);
}

/**
 * not_found_error - hanlder for not found commands
 * @p: struct with all vars
 */
void not_found_error(params p)
{
	int error_len;
	char error_msg[64] = "./hsh: ";
	char *cnt = _itoa(*(p.loop));

	_strcat(error_msg, cnt);
	_strcat(error_msg, ": ");
	_strcat(error_msg, p.argv[0]);
	_strcat(error_msg, ": not found\n");
	free(cnt);

	error_len = _strlen(error_msg);

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
	struct stat found;

	p.cmd = cmd_path(p.argv);

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
