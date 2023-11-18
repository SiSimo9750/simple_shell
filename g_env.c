#include "shell.h"

/**
 * mygetenv - will get you the env
 * @var: input variable
 *
 * Return: environ or NULL
 */
char *mygetenv(char *var)
{
		int indx;
		char *tempo, *ke, *val1, *val2;

		for (indx = 0; environ[indx]; indx++)
		{
			tempo = _strdup(environ[indx]);
			ke = strtok(tempo, "=");
			if (_strcmp(ke, var) == 0)
			{
				val1 = strtok(NULL, "\n");
				val2 = _strdup(val1);
				free(tempo);
				return (val2);
			}
			free(tempo), tempo = NULL;
		}
		return (NULL);
}
