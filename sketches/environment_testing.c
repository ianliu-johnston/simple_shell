#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define BUFSIZE 1024
/**
  * struct environ_path - linked list from PATH
  * @path: path in the format /usr/bin
  * @len: length of the string
  * @next: points to the next node
  */
typedef struct environ_path
{
	char *str;
	unsigned int len;
	struct environ_path *next;
} env_path_t;
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
	dupstr = strdup(str);
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
/**
  * print_list - prints a linked list
  * @h: linked list to print
  * Return: length of linked list
 (*
  * used for debugging linked lists.
  */
size_t print_list(const env_path_t *h)
{
	size_t i;

	for (i = 0; h; i++)
	{
		printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}
	return (i);
}
char *search_os(char *cmd)
{
	char *abs_path;
	env_path_t *ep;

	ep = list_from_path();
	if (ep == NULL)
		perror("List empty.\n"), exit(99);
	/*
	print_list(ep);
	*/

	while (ep)
	{
		abs_path = strdup(ep->str);
		abs_path = strcat(abs_path, cmd);
		/*
		printf("abs_path: %s\n", abs_path);
		*/
		if (access(abs_path, F_OK | X_OK) == 0)
		{
			/*
			printf("found it\n");
			*/
			return(abs_path);
		}
		ep = ep->next;
	}
	/*
	printf("Didn't find it\n");
	*/
	return (NULL);
}
/**
  * main - Entry point
  * Return: 0 on success
  */
int main(int ac, char *av[])
{
	char *path;
	if (ac != 2)
		perror("Usage: ./a.out <command_to_find>"), exit(100);
	path = search_os(av[1]);
	if (path)
		printf("%s\n", path);
	else
		printf("Did not find command\n");
	return (0);
}
