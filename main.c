#include <shell.h>

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
	int stts = 0;
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

		mycmd = tknsplit(myline);
		if (!mycmd)
			continue;

	}

}
