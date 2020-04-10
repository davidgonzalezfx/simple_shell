#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Core simple shell functions */
void simple_exec(char **argv, int *loop, int *error, struct stat found);

/* Auxiliar functions */
int _strcmp(char *s1, char *s2);
void signal_exit(int a);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif /*SHELL_H*/

