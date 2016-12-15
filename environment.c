#include "utilities.h"
#include "environment.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
  * add_node - adds a new node to the end of a linked list
  * @head: head of the linked list
  * @str: string
  * @len: length of the string
  * Return: pointer to the current position in the list
  **/
env_path_t *add_node(env_path_t **head, char *str, unsigned int len)
{
	env_path_t *new, *walk;
	char *dupstr;

	if (str == NULL)
		return (NULL);
	dupstr = _strdup(str);
	if (dupstr == NULL)
		return (NULL);
	new = malloc(sizeof(env_path_t));
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
env_path_t *list_from_path(void)
{
	unsigned int len, i, j;
	char *env;
	char buffer[BUFSIZE];
	env_path_t *ep;

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
char *search_os(char *cmd)
{
	char *abs_path;
	env_path_t *ep;

	ep = list_from_path();
	if (ep == NULL)
	{
		perror("List empty.\n");
		return(NULL);
	}
	while (ep)
	{
		abs_path = _strdup(ep->str);
		abs_path = _strcat(abs_path, cmd);
		if (access(abs_path, X_OK) == 0)
			return(abs_path);
		ep = ep->next;
	}
	return (NULL);
}