#include "shell.h"

/**
 * freemyarr - to free my input array
 * @myarr: input
 *
 * Return: nothing
 */

void freemyarr(char **myarr)
{
	int i;

	if (!myarr)
		return;
	for (i = 0; myarr[i]; i++)
	{
		free(myarr[i]);
		myarr[i] = NULL;
	}
	free(myarr);
	myarr = NULL;

}
