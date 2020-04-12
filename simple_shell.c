#include "shell.h"

/**
 * main - our own UNIX cli
 * Return: 0
 */
int main(void)
{
	char *buff = NULL, *aux = NULL, *path = _getenv("PATH"), *pathcp;
	struct stat found;
	size_t len = 0;
	int error = 0, loop = 1;
	node_path_t *head_of_path;

	signal(SIGINT, signal_exit);
	signal(SIGTSTP, SIG_IGN);
	do {
		printf("hsh$ ");
		error = getline(&buff, &len, stdin);
		if (error == -1)
			return (free(buff), printf("\n"), -1);
		if (error == 1)
			continue;
		aux = strchr(buff, '\n');
		if (aux != NULL)
			*aux = '\0';
		int tkn = 0;
		char *argv[] = {NULL, NULL, NULL, NULL};

		aux = strtok(buff, " ");
		while (aux)
		{
			argv[tkn] = aux;
			aux = strtok(NULL, " ");
			tkn++;
		}
		pathcp = get_cp_path(path);
		head_of_path = create_linked_path(pathcp);
		simple_exec(argv, &loop, &error, found, head_of_path);
		free(pathcp);
		loop++;
	} while (error != EOF);
	return (0);
}
