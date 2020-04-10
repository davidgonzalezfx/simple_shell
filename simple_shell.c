#include "shell.h"

/**
 * main - our own UNIX cli
 * Return: 0
 */
int main(void)
{
	char *buff = NULL, *aux = NULL;
	struct stat found;
	size_t len = 0;
	int error = 0, loop  = 1;

	signal(SIGINT, signal_exit);
	signal(SIGTSTP, SIG_IGN);
	do {
		if (isatty(STDIN_FILENO) == 1)
			write(1, "hsh$ ", 5);
		error = getline(&buff, &len, stdin);
		if (error == -1)
			return (free(buff), -1);
		if (error == 1)
			continue;
		aux = strchr(buff, '\n');
		if (aux != NULL)
			*aux = '\0';
		int tkn = 0;

		char **argv = _calloc(128, 8);

		if (!argv)
			return (-1);

		aux = strtok(buff, " ");
		while (aux)
		{
			argv[tkn] = aux;
			aux = strtok(NULL, " ");
			tkn++;
		}
		simple_exec(argv, &loop, &error, found);
		free(argv);
		loop++;
	} while (error != EOF);
	free(buff);
	return (0);
}
