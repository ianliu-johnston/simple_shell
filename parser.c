#include "shell.h"
/**
 * _getline - gets line from STDIN and places it in the buffer
 * @file: int assigned to the read of STDIN
 * Return: pointer to buffer with formatted input from STDIN
 */
char *_getline(int file)
{
	unsigned int i, index;
	char *buffer;
	static unsigned int buffer_size = BUFSIZE;

	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer == NULL)
	{
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	index = 0;
	_memset(buffer, '\0', buffer_size);
	while ((i = read(file, buffer + index, buffer_size - index)) > 0)
	{

		if (i < (buffer_size - index))
			return (buffer);
		buffer_size *= 2;
		_realloc(buffer, buffer_size, buffer_size / 2);
		if (buffer == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		index += i;
	}
	if (i == 0)
	{
		_memcpy(buffer, "exit", 5);
		return (buffer);
	}
	return (buffer);
}
/**
  * parser - parses a string into tokens
  * @str: string to parse
  * @delimit: delimiters chosen by user
  * @wd: char to determine wordcount of string
  * Return: Double pointer to array of tokens
  */
char **parser(char *str, char *delimit, char wd)
{
	char **tokenized, *saveptr, *token;
	unsigned int i, wc;

	wc = word_count(str, wd);
	tokenized = malloc((wc + 1) * sizeof(char *));
	if (tokenized == NULL)
	{
		perror("malloc failed\n");
		return (NULL);
	}
	token = _strtok_r(str, delimit, &saveptr);
	tokenized[0] = token;
	i = 1;
	while (token)
	{
		token = _strtok_r(NULL, delimit, &saveptr);
		tokenized[i] = token;
		i++;
	}
	return (tokenized);
}
/** Global variable: Flag, to handle interrupt signals **/
unsigned char flag = 0;
/**
  * sighandler - handles signals from keyboard interrupts
  * @sig: the signal caught
  */
static void sighandler(int sig)
{

	if (sig == SIGINT && flag == 0)
		simple_print("\nAnd baby says: ");
	else if (flag != 0)
		simple_print("\n");
}
/**
  * reader - reads user input and forms it into a string.
  */
void reader(void)
{
	char *buffer, **tokens;
	env_t *linkedlist_path;

	if (signal(SIGINT, sighandler) == SIG_ERR)
		perror("signal error\n");
	linkedlist_path = list_from_path();
	while (1)
	{
		flag = 0;
		simple_print("And baby says: ");
		buffer = _getline(STDIN_FILENO);
		tokens = parser(buffer, "\t\n ", ' ');
		if (is_builtin(tokens[0]))
			is_builtin(tokens[0])(tokens, linkedlist_path, buffer);
		else
		{
			flag = 1;
			executor(tokens, linkedlist_path);
		}
		free(tokens);
		free(buffer);
	}
}
