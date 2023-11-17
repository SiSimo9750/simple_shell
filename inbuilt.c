#include "shell.h"

/**
 * isbuiltin - will get you the path
 * @mycmd: input command
 *
 * Return: the path or NULL
 */
int isbuiltin(char *mycmd)
{
	char *builtlist[] = {"exit", "env", "setenv", "cd", NULL};
	int i;
	
	for (i = 0; builtlist[i]; i++)
	{
		if(_strcmp(mycmd, builtlist[i]) == 0)
			return (1);
	}
	return(0);
}
/**
 * getbuiltin - will get you the builtin cmnds
 * @mycmd: input command
 * @argv: input argv
 * @stts: input status
 * @idx: input index
 * Return: nothing
 */
void getbuiltin(char **mycmd, char **argv, int *stts, int idx )
{
	if (_strcmp(mycmd[0], "exit") == 0)
		quite_shell(mycmd, stts);
	else if (_strcmp(mycmd[0], "env") == 0)
		show_env(mycmd, stts);
}
/**
 * quite_shell - will exit our shell
 * @mycmd: input command
 * @stts: input status
 * Return: nothing
 */

void quite_shell(char **mycmd, int *stts)
{
	freemyarr(mycmd);
	exit(*stts);
}
/**
 * show_env - will print our shell env
 * @mycmd: input command
 * @stts: input status
 * Return: nothing
 */

void show_env(char **mycmd, int *stts);
{
	int i;
	
	for(i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}		
	freemyarr(mycmd);
	*stts = 0;
}
