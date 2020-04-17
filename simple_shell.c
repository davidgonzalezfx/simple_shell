#include "shell.h"

/**
 * test - function used in refactor
 * @p: struct with all vars
 * Return: int
 */
int test(params *p)
{
	int tkn;
	char *aux = NULL;

	aux = _strchr(p->buff, '\n');
	if (aux != NULL)
		*aux = '\0';
	tkn = 0;
	p->argv = _calloc(128, 8);
	if (!p->argv)
		return (-1);
	aux = strtok(p->buff, " ");
	if (!aux)
		return (free(p->argv), 1);
	while (aux)
	{
		p->argv[tkn++] = aux;
		aux = strtok(NULL, " ");
	}
	simple_exec(p);
	free(p->argv);

	return (1);
}
/**
 * main - our own UNIX cli
 * @ac: arguments cound
 * @av: argument array
 * Return: 0
 */
int main(int __attribute__((unused)) ac, char **av)
{
	int error = 0;
	int loop = 1;
	size_t len = 0;

	params p;

	p.argv = NULL;
	p.buff = NULL;
	p.cmd = NULL;
	p.name = av[0];
	p.exit_value = 0;
	p.loop = &loop;

	signal(SIGINT, signal_exit);
	signal(SIGTSTP, SIG_IGN);
	while (error != EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "hsh$ ", 5);
		error = getline(&p.buff, &len, stdin);
		if (error == -1)
			break;
		if (error != 1)
			error = test(&p);
		loop++;
	}
	free(p.buff);
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	return (p.exit_value);
}
