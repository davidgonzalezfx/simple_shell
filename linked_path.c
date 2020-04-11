#include "shell.h"

extern char **environ;

node_path_t *add_node_list(node_path_t **head, const char *str)
{
    node_path_t *new = malloc(sizeof(node_path_t)), *last = NULL;

    if (!new)
        return (NULL);

    new->path = str;
    new->next = NULL;

    if (!*head){
        *head = new;
    }
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

node_path_t *create_linked_path(){
 	char *path = NULL, *token;
    	node_path_t *head = NULL;
    	int i = 0;

    	while (environ[i])
    	{
        	path = strtok(environ[i], "=");
	        if (strcmp("PATH", path) == 0)
	        {
	            path =  strtok(NULL, "=");
	            break;
 		}
        	i++;
    	}

    	token = strtok(path, ":");
    	while (token)
    	{
        	add_node_list(&head, str_concat(token, "/")); 
        	token = strtok(NULL, ":");
    	}
    	return(head);
}

char *search_in_path(const char *command)
{
	node_path_t *head = create_linked_path(), *current = head;
	struct stat statbuff;
	char *path;

	while (current)
    {
		path = str_concat(current->path, command);
		if (stat(path, &statbuff) == 0)
			return (path);
		current = current->next;
	} 
	return (NULL);
}