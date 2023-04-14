#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int to print in binary
 *
 * Return: no return
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 0;
	int flag = 0;

	mask = ~0UL >> 1;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
		mask >>= 1;
	}
}
