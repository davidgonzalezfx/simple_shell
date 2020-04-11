#include "shell.h"
/**
 * simple_exec - core of simple_shell
 * @argv: arguments for cli
 * @loop: num of iteration
 * @error: getline status
 * @found: checker of files
 */
void simple_exec(char *argv[], int *loop, int *error, struct stat found, node_path_t *h)
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
			execve(argv[0], argv, NULL);	
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
		printf("./hsh: %i: %s: not found\n", *loop, argv[0]);
	free(pathname);
}
