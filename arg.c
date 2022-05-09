#include <stdio.h>

/**
 * main - print all arguement wihout ac
 * @ac: arguement count
 * @av: arguemtnt vraible
 *
 * Return: just zero
 */

int main(int ac, char **av)
{
	int i = 0;

	while(av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
