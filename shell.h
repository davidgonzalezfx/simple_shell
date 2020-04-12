#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct nodepath - 
 * @path: the path to its points
 * @nexxt: the next node path
 */
typedef struct node_path
{
	char *path;
	struct node_path *next;
}node_path_t;

/* Core simple shell functions */

void simple_exec(char **argv, int *loop,
								 int *error, struct stat found,
								 char **environ,
                 node_path_t *h);

/* Auxiliar functions */
int _strcmp(char *s1, char *s2);
void signal_exit(int a);

size_t print_list(const node_path_t *h);
node_path_t *add_node_list(node_path_t **head, const char *str);
char *str_concat(const char *s1, const char *s2);
unsigned int _strlength(const char *p);
char *search_in_path(const char *command, node_path_t *head);
node_path_t *create_linked_path(char *path);
void free_list(node_path_t *head);
char *_strdup(char *str);
char *_getenv(const char *name);
char *get_cp_path(char *path);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void rev_string(char *s);
char *_itoa(unsigned int num);

#endif /*SHELL_H*/

