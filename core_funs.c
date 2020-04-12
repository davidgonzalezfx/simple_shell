#include "shell.h"
/**
 * simple_exec - core of simple_shell
 * @argv: arguments for cli
 * @loop: num of iteration
 * @error: getline statuss
 * @found: checker of files
 * @environ: environment vars
 * @h: head to list
 */

void simple_exec(char **argv, int *loop,
								 int *error, struct stat found,
								 char **environ,
                node_path_t *h)
{
	char *pathname;

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
	else if ((pathname = search_in_path(argv[0], h)) != NULL)
	{
		if (fork() == 0)
			execve(pathname, argv, NULL);
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
  free(pathname);
	free_list(h);
}
