#include "shell.h"
/**
  * list_from_path - builds a linked list from PATH
  * Return: pointer to linked list
  */
env_t *list_from_path(void)
{
	unsigned int len, i, j;
	char *env;
	char buffer[BUFSIZE];
	env_t *ep;

	ep = NULL;
	len = i = j = 0;
	env = _getenv("PATH");
	while (*env)
	{
		buffer[j++] = *env;
		len++;
		if (*env == ':')
		{
			len--;
			buffer[j - 1] = '/';
			buffer[j] = '\0';
			add_node(&ep, buffer, len);
			len = j = 0;
		}
		env++;
	}
	return (ep);
}
/**
  * environ_linked_list - builds a linked list from PATH
  * Return: pointer to linked list
  */
env_t *environ_linked_list(void)
{
	int i, j;
	char **env;
	env_t *ep;

	ep = NULL;
	i = j = 0;
	env = environ;
	while (env[i])
	{
		add_node(&ep, env[i], (unsigned int)_strlen(env[i]));
		i++;
	}
	return (ep);
}
/**
  * search_os - search through os to find a command
  * @cmd: command to search for
  * @linkedlist_path: path to search through
  * Return: String to absolute path if found, NULL if not
  */
char *search_os(char *cmd, env_t *linkedlist_path)
{
	int status;
	char *abs_path;
	env_t *ep;

	ep = linkedlist_path;
	if (ep == NULL || cmd == NULL)
		return (NULL);
	if ((_strncmp(cmd, "/", 1) == 0
			|| _strncmp(cmd, "./", 2) == 0)
			&& access(cmd, F_OK | X_OK) == 0)
	{
		abs_path = _strdup(cmd);
		return (abs_path);
	}
	while (ep != NULL)
	{
		abs_path = _strdup(ep->str);
		if (abs_path == NULL)
			return (NULL);
		abs_path = _strcat_realloc(abs_path, cmd);
		if (abs_path == NULL)
			return (NULL);
		status = access(abs_path, F_OK | X_OK);
		if (status == 0)
			return (abs_path);
		free(abs_path);
		ep = ep->next;
	}
	return (NULL);
}
