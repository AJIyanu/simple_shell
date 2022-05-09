#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *c;
	size_t line = 0;

	printf("$ ");
	getline(&c, &line, stdin);
	printf("word scanned now printing\n");
	printf("%s\n", c);
	free(c);
	return (0);
}
