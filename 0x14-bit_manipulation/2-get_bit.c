#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 *
 * @n: The number to extract the bit from.
 * @index: The index of the bit to extract.
 *
 * Return: The value of the bit at index or -1 if an error occured.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int max_bits = sizeof(unsigned long int) * 8;

	if (index >= max_bits)
		return (-1);

	return ((n >> index) & 1);
}
