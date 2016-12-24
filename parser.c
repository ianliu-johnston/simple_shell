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
		_memcpy(buffer, "exit", 5);
	return (buffer);
}
/**
  * parser - parses a string into tokens
  * @str: string to parse
  * @delimit: delimiters chosen by user
  * Return: Double pointer to array of tokens
  */
char **parser(char *str, char *delimit)
{
	char **tokenized, *saveptr, *token;
	unsigned int i, wc;

	wc = word_count(str);
	tokenized = malloc((wc + 1) * sizeof(char *));
	if (!tokenized)
	{
		perror("malloc failed\n");
		return (NULL);
	}
	tokenized[0] = token = _strtok_r(str, delimit, &saveptr);
	for (i = 1; token; i++)
		tokenized[i] = token = _strtok_r(NULL, delimit, &saveptr);
	return (tokenized);
}
/** Global variable: Flag, to handle interrupt signals **/
unsigned char sig_flag = 0;
/**
  * sighandler - handles signals from keyboard interrupts
  * @sig: the signal caught
  */
static void sighandler(int sig)
{

	if (sig == SIGINT && sig_flag == 0)
		simple_print("\nAnd baby says: ");
	else if (sig_flag != 0)
		simple_print("\n");
}
/**
  * main - entry point
  * Return: 0 on successful termination. -1 on failure.
  */
int main(void)
{
	char pipe_flag, *buffer, *cmds, *saveptr, **tokens;
	env_t *linkedlist_path;
	struct stat fstat_buf;

	if (signal(SIGINT, sighandler) == SIG_ERR)
		perror("signal error\n");
	if (fstat(STDIN_FILENO, &fstat_buf) == -1)
		perror("fstat error\n"), exit(98);
	pipe_flag = (fstat_buf.st_mode & S_IFMT) == S_IFCHR ? 0 : 1;
	linkedlist_path = list_from_path();
	if (linkedlist_path == NULL)
		return (-1);
	saveptr = NULL;
	while (1)
	{
		sig_flag = 0;
		if (pipe_flag == 0)
			simple_print("And baby says: ");
		buffer = _getline(STDIN_FILENO);
		if (!buffer)
			break;
		cmds = _strtok_r(buffer, "\n;", &saveptr);
		while (cmds)
		{
			tokens = parser(cmds, "\t ");
			if (!tokens)
				break;
			if (is_builtin(tokens[0]))
				is_builtin(tokens[0])(tokens, linkedlist_path, cmds);
			else
				sig_flag = 1, executor(tokens, linkedlist_path);
			free(tokens);
			cmds = _strtok_r(NULL, "\n;", &saveptr);
		}
		free(buffer);
	}
	return (0);
}
