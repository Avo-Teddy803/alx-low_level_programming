#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: a string representing a binary number
 *
 * Return: the unsigned int representation of the binary number,
 *         or 0 if b is NULL or contains non-binary characters
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int len = 0;
	unsigned int bit = 1;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		len++;
	}

	len--;

	while (len >= 0)
	{
		if (b[len] == '1')
			res += bit;

		bit *= 2;
		len--;
	}

	return (res);
}
