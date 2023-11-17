#include "shell.h"
/**
 * tknsplit - function to split tokens
 * @myline: the typed line
 * Return: array of tokens or NULL
 */
char **tknsplit(char *myline)
{
	char *tkn = NULL, *tmp = NULL;
	char delim[] = " \t\n";
	char **mycmd = NULL;
	int cnt = 0;
	int ind = 0;

	if (!myline)
		return (NULL);
	tmp = _strdup(myline);
	tkn = strtok(tmp, delim);
	if (tkn == NULL)
	{	free(myline), myline = NULL;
		free(tmp), tmp = NULL;
		return (NULL);	}
	while (tkn)
	{	cnt++;
		tkn = strtok(NULL, delim);	}
	free(tmp), tmp = NULL;
	mycmd = malloc(sizeof(char *) * (cnt + 1));
	if (!mycmd)
	{	free(myline), myline = NULL;
		return (NULL);	}
	tkn = strtok(myline, delim);
	while (tkn)
	{	mycmd[ind] = _strdup(tkn);
		tkn = strtok(NULL, delim);
		ind++;	}
	free(myline), myline = NULL;
	mycmd[ind] = NULL;
	return (mycmd);
}
