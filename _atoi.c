#include "shell.h"

/**
 * interactive - returns true if only  shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if its interactive mode and then , 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the  character is a delimeter
 * @r: the char is to check
 * @delim: the delimeter string using
 * Return: 1 if true, 0 if false
 */
int is_delim(char r, char *delim)
{
	while (*delim)
		if (*delim++ == r)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for some  alphabetic character
 * @r: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int r)
{
	if ((r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer number
 * @g: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *g)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; g[i] != '\0' && flag != 2; i++)
	{
		if (g[i] == '-')
			sign *= -1;

		if (g[i] >= '0' && g[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (g[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
