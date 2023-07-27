#include "shell.h"

/**
 * tokenize - A function tokenizes string into multiple commands.
 *
 * @buffer: The string to tokenize.
 * @delim: The delimiter to use.
 * Return: An array of tokens.
 */
char **tokenize(char *buffer, const char *delim)
{
	char *token = NULL, **commands = NULL;
	size_t buffer_size = 0;
	int num = 0;

	if (buffer == NULL)
		return (NULL);

	buffer_size = _strlen(buffer);
	commands = malloc((buffer_size + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_memory(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, delim);
	while (token != NULL)
	{
		commands[num] = malloc(_strlen(token) + 1);
		if (commands[num] == NULL)
		{
			perror("Unable to allocate buffer");
			free_memory(commands);
			return (NULL);
		}
		_strcpy(commands[num], token);
		token = strtok(NULL, delim);
		num++;
	}
	commands[num] = NULL;
	return (commands);
}
