#include "shell.h"

/**
 * check_builtin - execute if argv is built-in command
 * @argv: arguments
 * @loop: used for print error
 * Return: int
 */
int check_builtin(char **argv, int *loop, char *cmd, char *buff)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
		{
			if (check_word(argv))
			{
				int status = atoi(argv[1]);

				free(cmd);
				free(buff);
				free(argv);
				exit(status);
			}
			else
			{
				char error_msg[64] = "./hsh: ";
				char *cnt = _itoa(*loop);

				_strcat(error_msg, cnt);
				_strcat(error_msg, ": ");
				_strcat(error_msg, argv[0]);
				_strcat(error_msg, ": Ilegal number: ");
				_strcat(error_msg, argv[1]);
				_strcat(error_msg, "\n");
				free(cnt);
				int error_len = _strlen(error_msg);

				write(2, error_msg, error_len);
				return (1);
			}
		}
		free(cmd);
		free(buff);
		free(argv);
		exit(0);
	}
	return (0);
}

/**
 * not_found_error - hanlder for not found commands
 * @loop: for print cicle num
 * @argv: for print what wasn't found
 */
void not_found_error(int *loop, char **argv)
{
	char error_msg[64] = "./hsh: ";
	char *cnt = _itoa(*loop);

	_strcat(error_msg, cnt);
	_strcat(error_msg, ": ");
	_strcat(error_msg, argv[0]);
	_strcat(error_msg, ": not found\n");
	free(cnt);
	int error_len = _strlen(error_msg);

	write(2, error_msg, error_len);
}

/**
 * non_interactive - handler for non interactive mode
 * @cmd: absolute path of argv[0] command
 * @argv: arguments from getline()
 * @loop: for not_found_error
 * Return: void
 */
void non_interactive(char *cmd, char **argv, int *loop, char *buff)
{
	struct stat found;

	if (check_builtin(argv, loop, cmd, buff) == 1)
		return;
	else if (cmd)
	{
		if (fork() == 0)
			execve(cmd, argv, environ);
		else
		{
			wait(NULL);
			return;
		}
	}
	else if (stat(argv[0], &found) == 0)
	{
		if (fork() == 0)

			execve(argv[0], argv, environ);
		else
		{
			wait(NULL);
			return;
		}
	}
	else
		not_found_error(loop, argv);
}

/**
 * simple_exec - core of simple_shell
 * @argv: arguments for cli
 * @loop: num of iteration
 * @found: checker of files
 * @environ: environment vars
 */
void simple_exec(char **argv, int *loop, struct stat found,
								 char **environ, char *buff)
{
	char *cmd = cmd_path(argv);

	if (isatty(STDIN_FILENO) != 1)
		non_interactive(cmd, argv, loop, buff);
	else if (check_builtin(argv, loop, cmd, buff) == 1)
		return;
	else if (stat(argv[0], &found) == 0)
	{
		if (fork() == 0)
			execve(argv[0], argv, environ);
		else
			wait(NULL);
	}
	else if (cmd)
	{
		if (fork() == 0)
			execve(cmd, argv, environ);
		else
			wait(NULL);
	}
	else
		not_found_error(loop, argv);
	free(cmd);
}
