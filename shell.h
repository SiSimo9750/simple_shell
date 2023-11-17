#ifndef MY_SHELL_H
#define MY_SHELL_H
	
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>

extern char **environ;

char *readmyline(void);
char **tknsplit(char *myline);
int _exec(char **mycmd, char **argv);
void freemyarr(char **myarr);


int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

#endif
