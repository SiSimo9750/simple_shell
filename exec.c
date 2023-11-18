#include "shell.h"

/**
 * _exec - my execute function
 * @mycmd: array of commands to execute
 * @argv: arguments
 * @idx: index parameter
 *
 * Return: the exit status
 */

int _exec(char **mycmd, char **argv, int idx)
{
	char *myfullcmd;
	pid_t ch_pid;
	int stts;

	myfullcmd = mygetpath(mycmd[0]);
	if (!myfullcmd)
	{
		showerror(argv[0], mycmd[0], idx);
		freemyarr(mycmd);
		return (127);
	}
	ch_pid = fork();
	if (ch_pid == 0)
	{
		if (execve(myfullcmd, mycmd, environ) == -1)
		{
			free(myfullcmd), myfullcmd = NULL;
			freemyarr(mycmd);
		}

	}
	else
	{
		waitpid(ch_pid, &stts, 0);
		freemyarr(mycmd);
		free(myfullcmd), myfullcmd = NULL;
	}
	return (WEXITSTATUS(stts));
}
