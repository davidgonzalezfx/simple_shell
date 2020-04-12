#include "shell.h"

extern char **environ;

node_path_t *add_node_list(node_path_t **head, const char *str)
{
		node_path_t *new = malloc(sizeof(node_path_t)), *last = NULL;

		if (!new)
			return (NULL);

		new->path =  str_concat(str, "/");
		new->next = NULL;

		if (!*head)
		   	*head = new;
		else
		{
			last = *head;
			while (last->next)
					last = last->next;
			last->next = new;
		}
		return(*head);
}

	
char *_getenv(const char *name)
{
	char *current_env = NULL;
	int i = 0;

	while (environ[i])
	{
		current_env = strtok(environ[i], "=");
		if (strcmp(name, current_env) == 0)
		{
				current_env =  strtok(NULL, "=");
				break;
		}
		current_env = "(null)";
		i++;
	}        
	return (current_env);
}

node_path_t *create_linked_path(char *path)
{
 	char *token;
	node_path_t *head = NULL;

	token = strtok(path, ":");
	while (token)
	{
		add_node_list(&head,token); 
		token = strtok(NULL, ":");
	}
	return(head);
}

char *search_in_path(const char *command, node_path_t *head)
{
	node_path_t *current = head;
	struct stat statbuff;
	char *path;

	while (current)
		{
		path = str_concat(current->path, command);
		if (stat(path, &statbuff) == 0)
			return (path);
		free(path);
		current = current->next;
	} 
	return (NULL);
}

size_t print_list(const node_path_t *h)
{
	size_t size = 0;

	while (h)
	{
		if (!(*h).path)
			printf("[0] (nil)\n");
		else
			printf("[%p] %s\n", (void *)(h), (*h).path);
		h = (*h).next, size++;
	}
	return (size);
}