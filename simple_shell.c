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

	do {
		printf("hsh$ ");
		error = getline(&buff, &len, stdin);
		if (error == -1)
		{
			perror("Error");
			printf(">buff: %s", buff);
			return (-1);
		}
		if (error == 1)
			continue;
		aux = strchr(buff, '\n');
		if (aux != NULL)
			*aux = '\0';
		aux = strtok(buff, " ");
		int tkn = 0;
		char *argv[] = {NULL, NULL, NULL, NULL};

		while (aux)
		{
			argv[tkn] = aux;
			aux = strtok(NULL, " ");
			tkn++;
		}
		simple_exec(argv, &loop, &error, found);
	} while (error != EOF);
	free(buff);
	return (0);
}
