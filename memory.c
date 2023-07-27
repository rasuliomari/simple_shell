#include "shell.h"

/**
 * free_memory - This function that frees all the memory
 * allocated for commands.
 *
 * @command: Pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_memory(char **command)
{
	size_t num = 0;

	if (command == NULL)
		return;

	while (command[num])
	{
		free(command[num]);
		num++;
	}

	if (command[num] == NULL)
		free(command[num]);
	free(command);
}


/**
 * freeMem_and_exit - A function frees all the memory
 * allocated and exit.
 *
 * @command: The pointer to allocated commands memory to free.
 * Return: Nothing.
 */
void freeMem_and_exit(char **command)
{
	size_t num = 0;

	if (command == NULL)
		return;

	while (command[num])
	{
		free(command[num]);
		num++;
	}

	if (command[num] == NULL)
		free(command[num]);
	free(command);
	exit(EXIT_FAILURE);
}
