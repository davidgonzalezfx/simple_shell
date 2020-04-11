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
	int error = 0, loop = 1;
	node_path_t *head_of_path = create_linked_path();

	signal(SIGINT, signal_exit);
	signal(SIGTSTP, SIG_IGN);
	print_list(head_of_path);
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
		simple_exec(argv, &loop, &error, found, head_of_path);
		loop++;
	} while (error != EOF);
	printf("trying to free list");
	free_list(head_of_path);
	printf("lst freed");
	free(buff);
	return (0);
}
