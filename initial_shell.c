#include "shell.h"

/**
 * prompt_handler - A prompt handler function that prints the prompt
 *
 * Return: Nothing.
 */
void prompt_handler(void)
{
	if (isatty(STDIN_FILENO))
	{
		const char *prompt = "alx_shell[$] ";

		write(STDOUT_FILENO, prompt, 13);
	}
}


/**
 * handle_signal - A signal handler function to handle cancel signal.
 *
 * @signal: Signal to be handled.
 * Return: Nothing.
 */
void handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		const char *signal = "\nalx_shell[$] ";

		write(STDOUT_FILENO, signal, 14);
	}
}

/**
 * handle_exit - A handle_exit function that exits
 * the shell when required.
 *
 * @input_command: Tokenized pointer command.
 * Return: Nothing.
 */
void handle_exit(char **input_command)
{
	int status = 0;

	if (input_command[1] != NULL)
		status = _strint(input_command[1]);

	free_memory(input_command);
	exit(status);
}


/**
 * handle_eof - A handle_eof function that chaecks if buffer is EOF or not
 *
 * @buffer: Pointer to the input string.
 * Return: Nothing
 */
void handle_eof(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	exit(EXIT_SUCCESS);
}
