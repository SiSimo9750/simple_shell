#include "shell.h"

/**
 * main - shell's main function
 * @ac: arguments counter
 * @argv: arguments variable
 *
 * Return: depends on the status
 */
int main(int ac, char **argv)
{
	char *myline = NULL;
	char **mycmd = NULL;
	int stts = 0, idx = 0;
	(void) ac;

	while (1)
	{
		myline = readmyline();
		if (myline == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stts);
		}
		idx++;

		mycmd = tknsplit(myline);
		if (!mycmd)
			continue;
		if (isbuiltin(mycmd[0]))
			getbuiltin(mycmd, argv, &stts, idx);
		else
			stts = _exec(mycmd, argv, idx);

	}

}
