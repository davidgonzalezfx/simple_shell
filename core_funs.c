#include "shell.h"
/**
 * simple_exec - core of simple_shell
 * @argv: arguments for cli
 * @loop: num of iteration
 * @error: getline status
 * @found: checker of files
 */
void simple_exec(char *argv[], int *loop, int *error, struct stat found)
{
	if (_strcmp("_which", argv[0]) == 0)
		argv[0] = "/bin/which";
	if (isatty(STDIN_FILENO) != 1)
	{
		*error = -1;
		execve(argv[0], argv, NULL);
	}
	if (stat(argv[0], &found) == 0)
	{

		if (fork() == 0)
			execve(argv[0], argv, NULL);
		else
			wait(NULL);
	}
	else
		printf("./hsh: %i: %s: not found\n", *loop, argv[0]);
	loop++;
}
