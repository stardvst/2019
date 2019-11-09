#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char *environ[];
int main()
{
	int index = 0;
	char **env = environ;
	printf("Environment variables:\n");
	index = 0;
	while (env[index])
	{
		printf("envp[%d]: %s\n", index, env[index]);
		++index;
	}
	return 0;
}
