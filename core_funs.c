#include "shell.h"
/**
 * simple_exec - core of simple_shell
 * @argv: arguments for cli
 * @loop: num of iteration
 * @error: getline status
 * @found: checker of files
 * @environ: environment vars
 */
void simple_exec(char **argv, int *loop,
								 int *error, struct stat found,
								 char **environ)
{
	if (isatty(STDIN_FILENO) != 1)
	{
		if (fork() == 0)
			execve(argv[0], argv, NULL);
		else
		{
			wait(NULL);
			*error = 0;
			return;
		}
	}
	if (stat(argv[0], &found) == 0)
	{
		if (fork() == 0)
			execve(argv[0], argv, environ);
		else
			wait(NULL);
	}
	else
	{
		char error_msg[64] = "./hsh: ";
		char *cnt = _itoa(*loop);

		_strcat(error_msg, cnt);
		_strcat(error_msg, ": ");
		_strcat(error_msg, argv[0]);
		_strcat(error_msg, ": not found\n");
		free(cnt);
		int error_len = _strlen(error_msg);

		write(1, error_msg, error_len);
	}
}
