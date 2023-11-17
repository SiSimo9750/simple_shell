#include "shell.h"

/**
 * _exec - my execute function
 * @mycmd: array of commands to execute
 * @argv: arguments
 *
 * Return: the exit status
 */

int _exec(char **mycmd, char **argv)
{
	pid_t ch_pid;
	int stts;

	ch_pid = fork();
	if (ch_pid == 0)
	{
		if (execve(mycmd[0], mycmd, environ) == -1)
		{
			perror(argv[0]);
			freemyarr(mycmd);
			exit(0);
		}

	}
	else
	{
		waitpid(ch_pid, &stts, 0);
		freemyarr(mycmd);
	}
	return (WEXITSTATUS(stts));
}
