#include "shell.h"

/**
 * check_builtin - execute if argv is built-in command
 * @p: struct with all vars
 * Return: int
 */
int check_builtin(params *p)
{
	if (_strcmp("exit", p->argv[0]) == 0)
		return (exit_built_in(p));
	else if (_strcmp("env", p->argv[0]) == 0)
		return (env_built_in(), 1);
	return (0);
}

/**
 * not_found_error - hanlder for not found commands
 * @p: struct with all vars
 */
void not_found_error(params *p)
{
	int error_len;
	char error_msg[64] = "";
	char *cnt = _itoa(*(p->loop));

	_strcpy(error_msg, p->name);
	_strcat(error_msg, ": ");
	_strcat(error_msg, cnt);
	_strcat(error_msg, ": ");
	_strcat(error_msg, p->argv[0]);
	_strcat(error_msg, ": not found\n");
	free(cnt);

	error_len = _strlen(error_msg);

	write(2, error_msg, error_len);
}

/**
 * simple_exec - core of simple_shell
 * @p: struct with all vars
 */
void simple_exec(params *p)
{
	struct stat found;
	int exit_execve;

	p->cmd = cmd_path(p->argv);

	if (check_builtin(p) == 1)
		return;
	else if (stat(p->argv[0], &found) == 0)
	{
		if (fork() == 0)
		{
			execve(p->argv[0], p->argv, environ);
			exit(0);
		}
		else
		{
			wait(&exit_execve);
			p->exit_value = WEXITSTATUS(exit_execve);
		}
	}
	else if (p->cmd)
	{
		if (fork() == 0)
		{
			execve(p->cmd, p->argv, environ);
			exit(0);
		}
		else
		{
			wait(&exit_execve);
			p->exit_value = WEXITSTATUS(exit_execve);
		}
	}
	else
		not_found_error(p);
	free(p->cmd);
}
