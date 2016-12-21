#include "shell.h"
/**
  * _getenv - gets the environment value from a key
  * @name: string to search through environments for
  * Return: value of the key as a string
  */
char *_getenv(const char *name)
{
	int i;
	char *token, *saveptr, *tmpname, **env;

	env = environ;
	tmpname = _strdup((char *)name);
	while (env)
	{
		token = _strtok_r(env->str, "=", &saveptr);
		if (_strncmp(tmpname, token, env->len) == 0)
		{
			free(tmpname);
			return (_strtok_r(NULL, "=", &saveptr));
		}
		env = env->next;
	}
	/*
	for (i = 0; env[i] != NULL; i++)
	{
		token = _strtok_r(env[i], "=", &saveptr);
		if (_strncmp(tmpname, token, _strlen(token)) == 0)
		{
			free(tmpname);
			return (_strtok_r(NULL, "=", &saveptr));
		}
	}
	*/
	free(tmpname);
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
  * Return: Success or failure
  */
int _setenv(const char *name, const char *value, int overwrite)
{
       int i, len_value;
       char *temp, **env;
       env_t *path;

       env = environ;
       path = list_from_path();
	   env++;
	   path++;

       if (name == NULL || *name == '\0')
		   return (0);
       for (i = 0; name[i] != '\0'; i++)
       {
		   if (name[i] == '=')
			   return (0);
       }
       len_value = _strlen_const(value);

       if ((temp = _getenv(name)) != NULL)
       {
		   if (overwrite == 0)
			   return (0);
		/*unset and add node*/
       }
	   len_value++;
	   /*
       else
	   */
		   /*
			add_node
			*/
	   return (0);
}

