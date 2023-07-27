#include "shell.h"

/**
 * execute_command - This function executes a command.
 *
 * @command: Tokenized command.
 * @shell_name: The name of the shell.
 * @env: Environmental variables.
 * @loops: Number of executed cycles.
 * Return: Nothing
 */
void execute_command(char **command, char *shell_name, char **env, int loops)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(shell_name);
			freeMem_and_exit(command);
		}
	}
	else
	{
		pathways = _dirsPATH(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(shell_name);
					free_memory(pathways);
					freeMem_and_exit(command);
				}
				return;
			}
		}
		command_error(shell_name, loops, command);
		free_memory(pathways);
	}
}


/**
 * print_env - Prints all environmental variables.
 *
 * @env: The environmental variables.
 * Return: Nothing
 */
void print_env(char **env)
{
	size_t num = 0, length = 0;

	while (env[num])
	{
		length = _strlen(env[num]);
		write(STDOUT_FILENO, env[num], length);
		write(STDOUT_FILENO, "\n", 1);
		num++;
	}
}


/**
 * _dirsPATH - Gets the directories for the
 * PATH environmental variable.
 *
 * @env: The environmental variables.
 * Return: An array of directories.
 */
char **_dirsPATH(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int num = 0;

	pathvalue = strtok(env[num], "=");
	while (env[num])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = tokenize(pathvalue, ":");
			return (pathways);
		}
		num++;
		pathvalue = strtok(env[num], "=");
	}
	return (NULL);
}


/**
 * command_error - Prints command not found error message.
 *
 * @shell_name: The name of the shell.
 * @loops: The number of executed cycles.
 * @command: The tokenized command.
 * Return: Nothing
 */
void command_error(char *shell_name, int loops, char **command)
{
	char result;

	result = loops + '0';
	write(STDOUT_FILENO, shell_name, _strlen(shell_name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &result, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
