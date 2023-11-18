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
char *mygetenv(char *var);
char *mygetpath(char *mycmd);
char **tknsplit(char *myline);
int _exec(char **mycmd, char **argv, int idx);
void freemyarr(char **myarr);
void showerror(char *name, char *mycmd, int myindex);
char *_itoa(int n);
void str_reverse(char *mystr, int len);
void getbuiltin(char **mycmd, char **argv, int *stts, int idx );
int isbuiltin(char *mycmd);
void quite_shell(char **mycmd, int *stts);
void show_env(char **mycmd, int *stts);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

#endif
