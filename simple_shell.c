#include "shell.h"
/**
 * main - our own UNIX cli
 * Return: 0
 */
int main(void)
{
	char *buff = NULL, *aux = NULL;
	params p;
	size_t len = 0;
	int error = 0, loop = 1;

	signal(SIGINT, signal_exit);
	signal(SIGTSTP, SIG_IGN);
	do {
		int tkn;
		char **argv;

		if (isatty(STDIN_FILENO) == 1)
			write(1, "hsh$ ", 5);
		error = getline(&buff, &len, stdin);
		if (error == -1)
			return (free(buff), -1);
		if (error == 1)
			continue;
		aux = _strchr(buff, '\n');
		if (aux != NULL)
			*aux = '\0';
		tkn = 0;
		argv = _calloc(128, 8);

		if (!argv)
			return (-1);
		aux = strtok(buff, " \t\n\v\r\a");
		while (aux)
		{
			argv[tkn] = aux;
			aux = strtok(NULL, " \t\n\v\r\a");
			tkn++;
		}
		p.argv = argv, p.loop = &loop, p.buff = buff;
		simple_exec(p);
		free(argv);
		loop++;
	} while (error != EOF);
	return (0);
}
