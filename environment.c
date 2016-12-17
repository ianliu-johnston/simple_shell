#include "shell.h"
/**
  * add_node - adds a new node to the end of a linked list
  * @head: head of the linked list
  * @str: string
  * @len: length of the string
  * Return: pointer to the current position in the list
  **/
env_t *add_node(env_t **head, char *str, unsigned int len)
{
	env_t *new, *walk;
	char *dupstr;

	if (str == NULL)
		return (NULL);
	dupstr = _strdup(str);
	if (dupstr == NULL)
		return (NULL);
	new = malloc(sizeof(env_t));
	if (new == NULL)
		return (NULL);
	new->str = dupstr;
	new->len = len;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	walk = *head;
	while (walk->next != NULL)
		walk = walk->next;
	walk->next = new;
	return (*head);
}
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
	env = getenv("PATH");
	while (*env)
	{
		buffer[j++] = *env;
		len++;
		if(*env == ':')
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
void free_list(env_t *head)
{
	if (head == NULL)
		return;
	free_list(head->next);
	free(head->str);
	free(head);
}
char *search_os(char *cmd, env_t *linkedlist_path)
{
	int status;
	char *abs_path;
	env_t *ep;

	ep = linkedlist_path;
	if (ep == NULL)
	{
		perror("List empty.\n");
		return(NULL);
	}
	while (ep != NULL)
	{
		abs_path = _strdup(ep->str);
		abs_path = _strcat_realloc(abs_path, cmd);
		status = access(abs_path, X_OK);
		if (status == 0)
			return(abs_path);
		free(abs_path);
		ep = ep->next;
	}
	return (NULL);
}
char *_getenv(const char *name)
{
	return (getenv(name));
}

int _setenv(const char *name, const char *value, int overwrite)
{
	return (setenv(name, value, overwrite));
}
int _unsetenv(const char *name)
{
	return (unsetenv(name));
}
