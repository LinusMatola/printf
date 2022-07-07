#include "main.h"

/**
 * otoa - convert an unsigned int to binary string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 * @spec: specifier flags
 *
 * Return: Always 0
 */
int otoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec)
{
	int i;
	unsigned long int b = va_arg(valist, unsigned long int);
	char s[12];

	if (!b)
	{
		string_to_buffer("0", buffer, pos, n_printed);
		return (0);
	}

	if (contains(spec, 'h'))
		b = (unsigned short) b;
	if (!contains(spec, 'l'))
		b = (unsigned int) b;

	if (contains(spec, '#'))
		string_to_buffer("0", buffer, pos, n_printed);

	for (i = 0; i < 12; i++)
		s[i] = '\0';
	i = 0;
	while (b > 0)
	{
		s[i] = (b % 8) + '0';
		b /= 8;
		i++;
	}

	rev_string(s);
	s[i] = '\0';

	string_to_buffer(s, buffer, pos, n_printed);
	return (0);
}
