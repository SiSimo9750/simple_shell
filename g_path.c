#include "shell.h"

/**
 * mygetpath - will get you the path
 * @mycmd: input command
 *
 * Return: the path or NULL
 */
char *mygetpath(char *mycmd)
{
	int indx;
	char *envpath, *myfullcmd, *d;
	struct stat stt;

	for (indx = 0; mycmd[indx]; indx++)
	{
		if ((mycmd[indx]) == '/')
		{
			if (stat(mycmd, &stt) == 0)
			return (_strdup(mycmd));
		return (NULL);
		}
	}

	envpath = mygetenv("PATH");

	if (!envpath)
		return (NULL);
	d = strtok(envpath, ":");
	while (d)
	{
		myfullcmd = malloc(_strlen(d) + _strlen(mycmd) + 2);
		if (myfullcmd)
		{
			_strcpy(myfullcmd, d);
			_strcat(myfullcmd, "/");
			_strcat(myfullcmd, mycmd);
			if (stat(myfullcmd, &stt) == 0)
			{
				free(envpath);
				return (myfullcmd);
			}
			free(myfullcmd), myfullcmd = NULL;
			d = strtok(NULL, ":");
		}
	}
	free(envpath);
	return (NULL);
}

