#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - super simple shell
 * Return: always zero
 */

int main(void)
{
	pid_t child_pid;
	int status;
	int i = 0;
	char add[15] = "../bin/";
	char argv[20];
	char *ptr[] = {add, NULL};


	while(1)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			printf("AJ@Super_shell $ ");
			scanf("%s", argv);
			while (argv[i] != '\0')
			{
				add[i + 7] = argv[i];
				i++;
			}
			add[i + 7] = '\0';
			printf("%s\n", add);
			if (execve(ptr[0], ptr, NULL) == -1)
				perror("Error:");
			i = 7;
			while (i < 15)
			{
				add[i] = '\0';
				i++;
			}
			i = 0;
		}
		else
			wait(&status);
	}
	return (0);
}

