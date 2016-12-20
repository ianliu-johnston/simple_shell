#include "shell.h"
/**
  * _getenv - gets value of environment variable
  */
char *_getenv(const char *name)
{
	int i;
	char *token, *saveptr, *tmpname, **env;

	env = environ;
	tmpname = _strdup((char *)name);
	for (i = 0; env[i] != NULL; i++)
	{
		token = _strtok_r(env[i], "=", &saveptr);
		if (_strncmp(tmpname, token, _strlen(token)) == 0)
			return (_strtok_r(NULL, "=", &saveptr));
	}
	return (NULL);
}
/**
  * main - entry point
  * Return: 0
  */
int main(void)
{
	char *home;

	home = _getenv("PATH");
	if (home == NULL)
		printf("Funky");
	else
		printf("%s\n", home);

	return (0);
}
