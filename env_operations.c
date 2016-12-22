#include "shell.h"
/**
  * _getenv - gets the environment value from a key
  * @name: string to search through environments for
  * Return: value of the key as a string
  */
char *_getenv(const char *name)
{
	int i, j, len;
	char **env, *tmp;

	if (!name)
		return (NULL);
	env = environ;
	for (i = 0; env[i]; i++)
	{
		for (len = 0; env[i][len] != '='; len++)
			;
		len++;
		tmp = malloc((len) * sizeof(char));
		_memcpy(tmp, env[i], len - 1);
		tmp[len - 1] = '\0';
		if (_strncmp((char *)name, tmp, _strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = NULL;
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					tmp = &env[i][j + 1];
					break;
				}
			}
			return (tmp);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
/**
  * _unsetenv - deletes a value from the environment.
  * @name: name of key=value pair to delete
  * Return: Success or failure
  */
int _unsetenv(const char *name)
{
	return (unsetenv(name));
}
/**
  * _setenv - adds or modifies a value from the environment.
  * @name: name of key=value pair
  * @value: value of the key=value pair
  * @overwrite: flag to determine whether to update if key exists
  * Return: 0 on success or -1 on failure
  */
int _setenv(const char *name, const char *value, int overwrite)
{
	return (setenv(name, value, overwrite));
}
