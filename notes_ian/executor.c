#include <stdio.h>
#include <unistd.h>

int executor(char *argv[])
{
	execve(argv[1], argv, NULL);
	return (0);
}

int main(int ac, char *av[], char **env)
{
	executor(av);
	ac++;
	env++;
	return (0);
}
