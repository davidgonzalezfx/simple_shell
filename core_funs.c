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
		return (env_built_in(p), 1);
	else if (_strcmp("setenv", p->argv[0]) == 0)
		return (set_env(p), 1);
	else if (_strcmp("unsetenv", p->argv[0]) == 0)
		return (unset_env(p), 1);
	return (0);
}


/**
 * fork_execute - create child process and execute cmd
 * @cmd: command or file to execute
 * @p: struct with arguments
 */
void fork_execute(char *cmd, params *p)
{
	pid_t check;
	int exit_execve;

	check = fork();
	if (check == 0)
		execve(cmd, p->argv, environ);
	else
	{
		wait(&exit_execve);
		p->exit_value = WEXITSTATUS(exit_execve);
	}
}

/**
 * simple_exec - core of simple_shell
 * @p: struct with all vars
 */
void simple_exec(params *p)
{
	struct stat found;
	DIR *check_fd = opendir(p->argv[0]);

	p->cmd = cmd_path(p->argv);

	if (_strcmp(p->argv[0], ".") == 0)
		closedir(check_fd);
	else if (check_builtin(p) == 1)
		return;
	else if (check_fd)
	{
		closedir(check_fd), p->exit_value = 126;
		not_permissions(p);
	}
	else if (p->argv[0][0] == '.' || p->argv[0][0] == '/')
	{
		if (stat(p->argv[0], &found) == 0)
		{
			if (access(p->argv[0], X_OK))
				not_permissions(p);
			else
				fork_execute(p->argv[0], p);
		}
	}
	else if (p->cmd)
	{
		fork_execute(p->cmd, p);
	}
	else
		not_found_error(p);
	free(p->cmd);
}
