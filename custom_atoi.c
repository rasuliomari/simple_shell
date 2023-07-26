#include "shell.h"

/**
 * is_interactive_mode - Checks if the shell is running in interactive mode.
 * @info: A pointer to the struct containing shell information.
 *
 * Description:
 * This function checks if the shell is being executed in interactive mode by
 * verifying if the standard input (file descriptor 0) is a terminal and if the
 * read file descriptor in the 'info' struct is less than or equal to 2 (standard output
 * and standard error file descriptors).
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int is_interactive_mode(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - Checks if a character is a delimiter.
 * @chara: The character to check.
 * @delimiter: The delimiter string.
 *
 * Description:
 * This function checks if a given character 'c' is present in the provided
 * delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delimiter(char chara, char *delimiter)
{
    while (*delimiter)
    {
        if (*delimiter == chara)
            return (1);
        delimiter++;
    }
    return (0);
}

/**
 * is_alpha_character - Checks if a character is alphabetic.
 * @chara: The character to check.
 *
 * Description:
 * This function checks if the given character 'c' is an alphabetic character,
 * either lowercase or uppercase.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int is_alpha_character(int c)
{
    if ((chara >= 'a' && chara <= 'z') || (chara >= 'A' && chara <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * string_to_integer - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Description:
 * This function takes a string 's' and converts it to an integer. It skips any
 * leading non-numeric characters and converts the subsequent numeric characters
 * to an integer. If the string does not contain any numbers, it returns 0.
 *
 * Return: The converted integer, or 0 if there are no numbers in the string.
 */
int string_to_integer(char *str)
{
    int a, signe = 1, f = 0, out;
    unsigned int res = 0;

    for (a = 0; str[a] != '\0' && f != 2; a++)
    {
        if (str[a] == '-')
            signe *= -1;

        if (str[a] >= '0' && str[a] <= '9')
        {
            f = 1;
            res *= 10;
            res += (str[a] - '0');
        }
        else if (f == 1)
            f = 2;
    }

    if (signe == -1)
        out = -res;
    else
        out = res;

    return (out);
}

