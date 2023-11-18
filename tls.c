#include "shell.h"
/**
 * freemyarr - to free my input array
 * @myarr: input
 * Return: nothing
 */
void freemyarr(char **myarr)
{
	int i;

	if (!myarr)
		return;
	for (i = 0; myarr[i]; i++)
	{	free(myarr[i]);
		myarr[i] = NULL;
	}
	free(myarr);
	myarr = NULL;
}
/**
 * showerror - will show an error
 * @name: input
 * @mycmd: input
 * @myindex: input
 * Return: nothing
 */
void showerror(char *name, char *mycmd, int myindex)
{
	char *i, msg[] = ": not found\n";

	i = _itoa(myindex);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, mycmd, _strlen(mycmd));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(i);
	}
/**
 * _itoa - integer to array converter
 * @n: input integer
 * Return: will return the result
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	str_reverse(buffer, i);
	return (_strdup(buffer));
}
/**
 * str_reverse - reverse a string order
 * @mystr: input string
 * @len: string's length
 * Return: nothing
 */
void str_reverse(char *mystr, int len)
{
	char tempo;
	int strt = 0;
	int end = len - 1;

	while (strt < end)
	{
		tempo = mystr[strt];
		mystr[strt] = mystr[end];
		mystr[end] = tempo;
		strt++;
		end--;
	}
}
