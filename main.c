#include "shell.h"
/**
 * main - prints prompt and calls reader to begin shell operations
 * Return: 0 on success
 */
int main(void)
{
	simple_print("Dance Magic Dance!\n");
	reader();
	return (0);
}
