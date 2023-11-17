#include "shell.h"

/**
 * readmyline - my getline function
 *
 * Return: input line or NULL
 */

char *readmyline(void)
{
	char *myline = NULL;
	size_t lngth = 0;
	ssize_t num;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	num = getline(&myline, &lngth, stdin);

	if (num == -1)
	{
		free(myline);
		return (NULL);
	}
	return (myline);
}
