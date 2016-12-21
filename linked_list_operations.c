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
  * free_list - frees a list
  * @head: beginning of the list
  */
void free_list(env_t *head)
{
	if (head == NULL)
		return;
	free_list(head->next);
	free(head->str);
	free(head);
}
/**
  * print_list - prints all elements of a list_t list
  * @h: singly linked list to print
  * Return: number of nodes in the list
  */
size_t print_list(const env_t *h)
{
	size_t i;

	for (i = 0; h; i++)
	{
		printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}
	return (i);
}
