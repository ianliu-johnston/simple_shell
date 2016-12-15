#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

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

env_path_t *add_node(env_path_t **head, char *str, unsigned int len);
env_path_t *list_from_path(void);
void free_list(env_path_t *head);
char *search_os(char *cmd, env_path_t *linkedlist_path);

#endif
