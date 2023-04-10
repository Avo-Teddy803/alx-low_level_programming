#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary number as a string.
 *
 * Return: the converted number, or 0 if b is NULL or contains
 * non-binary characters.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int len = 0;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		len++;
	}

	for (int i = len - 1, bit = 1; i >= 0; i--, bit <<= 1)
	{
		if (b[i] == '1')
			num += bit;
	}

	return (num);
}
