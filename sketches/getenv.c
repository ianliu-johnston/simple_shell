#include "shell.h"
/**
  * _getenv - gets value of environment variable
  */
char *_getenv(const char *name)
{
	int i, j, len;
	char **env;

	env = environ;
	for (len = 0; name[len]; len++)
		;
	for (i = 0; env[i]; i++)
		for ( j = 0; j < len && name[j] == env[i][j]; j++)
			if (j == len)
				return(env[i]);
	return (NULL);
}
/**
  * main - entry point
  * Return: 0
  */
int main(void)
{
	char *home;

	home = _getenv("HOME");
	printf("%s\n", home);
	return (0);
}
