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

/* Core simple shell functions */
void simple_exec(char **argv, int *loop, struct stat found, char **environ, char *buff);

/* Auxiliar functions */
int _strcmp(char *s1, char *s2);
void signal_exit(int a);

char *str_concat(const char *s1, const char *s2);
unsigned int _strlength(const char *p);
char *_strdup(char *str);
char *_getenv(const char *name);
char *get_cp_path(char *path);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void rev_string(char *s);
char *_itoa(unsigned int num);

/* PATH */
char *cmd_path(char **argv);

/* buil-ins */
int check_word(char **argv);

#endif /*SHELL_H*/

