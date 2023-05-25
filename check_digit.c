#include "monty.h"
/**
 * is_integer - checks if a string provided contains a valid integer
 * @str: characters to be checked if they are ints
 * Return: 0 if its not a valid int, 1 if its and integer
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		/*NULL checks if string is pointing to a valid address*/
		/*'/0' checks if its the first character marking end of string*/
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
