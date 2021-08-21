#ifndef _SHELL_
#define _SHELL_

/**
 * Libraries used by the project.
*/
#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* global constants */
#define TOKENS_BUFFER_SIZE 64
#define LINE_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

/**
 * array de string para leer el archivo de PATH
 */
extern char **environ;

void prompt(void);
char *_strcpy(char *dest, char *src); /* Funcion para copiar */
char *_strcpy(char *dest, char *src);
int _split(char *text);
#endif
