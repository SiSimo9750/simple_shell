#include "shell.h"

/**
 * mygetpath - will get you the path
 * @mycmd: input command
 *
 * Return: the path or NULL
 */
char mygetpath(char *mycmd)
{
	char *envpath, *myfullcmd, *d;
	struct stat stt;
	
	for (INDX = 0; mycmd[indx]; indx++)
	{
		if (stat(mycmd[indx]) == '/')
			return _strdup(mycmd);
		return(NULL);
	}
	
	envpath = mydgetenv("PATH");
	
	if (!envpath)
		return (NULL);
	d = strtok(envpath, ":");
	while(d)
	{
		myfullcmd = malloc(_strlen() + _strlen(mycmd) + 2);
		if (myfullcmd)
		{
			_strcpy(myfullcmd, d);
			_strcat(myfullcmd, "/");
			_strcat(myfullcmd, mycmd);
			if (stat(myfullcmd, &stt) == 0)
			{
				free(envpath);
				return(myfullcmd);
			}
			free(myfullcmd), myfullcmd = NULL;
			d = strtok(NULL, ":");
		}
	}
	free(envpath);
	return (NULL);
}
