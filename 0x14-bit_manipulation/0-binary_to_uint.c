/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: converted number, or 0 if there is one or more
 * chars in the string b that is not 0 or 1 or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ui = 0, base_two = 1;
	int len = 0;

	if (!b)
		return (0);

	while (b[len] != '\0')
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
		len++;
	}

	for (len--; len >= 0; len--, base_two *= 2)
	{
		if (b[len] & 1)
			ui += base_two;
	}

	return (ui);
