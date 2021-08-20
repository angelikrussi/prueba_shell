#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void prompt(void); /* imprime el prompt ($) */
char *getVariableFromEnviron(char *variableName); 
extern char **environ; /*array de string para leer el archivo de PATH*/

#endif
