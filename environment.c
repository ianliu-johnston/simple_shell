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
	printf("Linked List has been created.\n");
	return (ep);
}
void free_list(env_path_t *head)
{
	if (head == NULL)
		return;
	printf("Reached end of while in search_os\n");
	free_list(head->next);
	free(head->str);
	free(head);
}
char *search_os(char *cmd, env_path_t *linkedlist_path)
{
	int status;
	char *abs_path;
	env_path_t *ep;

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
		printf("%d\n", status);
		if (status == 0)
		{
			printf("Found a command: %s\n", abs_path);
			return(abs_path);
		}
		printf("didn't find command: %s\n", abs_path);
		free(abs_path);
		ep = ep->next;
	}
	return (NULL);
}
