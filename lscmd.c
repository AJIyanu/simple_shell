#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - function that creates five child processes in tur
 * Return: zero on success
 */

int main(void)
{
	pid_t child_pid;
	int status;
	int count = 0;
	char *argv[] = {"../bin/ls", "-l", "../tmp", NULL};

	while (count < 5)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
			wait(&status);
		count++;
	}
	return (0);
}

