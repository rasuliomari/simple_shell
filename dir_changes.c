#include "shell.h"

/**
  * dir_changes - This function changes the current working directory.
  *
  * @dir: New current working directory.
  * Return: 0 on success, -1 on failure.
  */
int dir_changes(const char *dir)
{
	char *buffer = NULL;
	size_t buffer_size = 1024;

	if (dir == NULL)
	{
		buffer = (char *)malloc(buffer_size * sizeof(char));
		dir = getcwd(buffer, buffer_size);
	}

	if (chdir(dir) == -1)
	{
		perror(dir);
		free(buffer);
		return (98);
	}

	free(buffer);
	return (1);
}
