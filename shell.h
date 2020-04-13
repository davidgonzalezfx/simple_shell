#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct params - object with all variables
 * @argv: arguments from user
 * @loop: num of times prompt has been showed
 * @found: used to find files with stat()
 * @buff: used with getline()
 * @cmd: command = path + argv[0]
 */
typedef struct params
{
	char **argv;
	int *loop;
	struct stat found;
	char *buff;
	char *cmd;
} params;

/* core_funs.c */
int check_builtin(params p);
void not_found_error(params p);
void non_interactive(params p);
void simple_exec(params p);

/* aux_funs.c */
void signal_exit(int a);
void *_calloc(unsigned int nmemb, unsigned int size);

/* path_funs.c */
char *_getenv(char *name);
char *cmd_path(char **argv);

/* string_funs.c */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void rev_string(char *s);
char *_itoa(unsigned int num);
int _strcmp(char *s1, char *s2);

/* string_funs_2.c */
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);

/* buil-ins.c */
int check_word(char **argv);

#endif /*SHELL_H*/

