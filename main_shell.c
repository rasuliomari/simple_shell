#include "shell.h"

/**
 * main - This is the main function that runs our shell.
 *
 * @argc: The number of input arguments.
 * @argv: The array of input arguments.
 * @envp: The array of environmental variables.
 * Return: Always 0 (success).
 */
int main(int argc, char **argv, char **envp)
{
	char *buffer = NULL;
	char **command = NULL;
	size_t buffer_size = 0;
	ssize_t checked_chars = 0;
	int loops = 0;
	(void)argc;

	while (1)
	{
		loops++;
		prompt_handler();
		signal(SIGINT, handle_signal);
		checked_chars = getline(&buffer, &buffer_size, stdin);

		if (checked_chars == EOF)
			handle_eof(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokenize(buffer, " \0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				handle_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				dir_changes(command[1]);
			else
				execute_child(command, argv[0], envp, loops);
		}
		fflush(stdin);
		buffer = NULL, buffer_size = 0;
	}
	if (checked_chars == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
