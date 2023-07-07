#include "main.h"

/**
 * print_binary - prints the binary representation of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	unsigned long int size = sizeof(n) * 8;
	int flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (size--)
	{
		if (n & (mask << size))
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
	}
}
