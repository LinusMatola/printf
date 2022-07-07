#include "main.h"

/**
 * ptoa - convert an address to hexadecimal string (lowercase)
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 * @spec: specifier flags
 *
 * Return: On success pointer to newly allocated string.
 * On error, NULL is returned.
 */
int ptoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec)
{
	int i;
	unsigned long b = va_arg(valist, unsigned long);
	char s[33];

	if (!b)
	{
		string_to_buffer("(nil)", buffer, pos, n_printed);
		return (0);
	}

	if (contains(spec, '+'))
		string_to_buffer("+", buffer, pos, n_printed);
	else if (contains(spec, ' '))
		string_to_buffer(" ", buffer, pos, n_printed);

	for (i = 0; i < 33; i++)
		s[i] = '\0';

	i = 0;
	while (b > 0)
	{
		s[i] = (b % 16);
		if ((b % 16) < 10)
			s[i] += '0';
		else
			s[i] += 'a' - 10;
		b /= 16;
		i++;
	}

	rev_string(s);
	s[i] = '\0';

	string_to_buffer("0x", buffer, pos, n_printed);
	string_to_buffer(s, buffer, pos, n_printed);

	return (0);
}
