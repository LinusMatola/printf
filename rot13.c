#include "main.h"

/**
 * rot13 - encode a string in rot13
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 * @spec: specifier flags
 *
 * Return: 0 on success else 1
 */
int rot13(va_list valist, char *buffer, int *pos, int *n_printed, char *spec)
{
	char w, c;
	char *s, *dest;
	int l, u, i;

	(void) spec;

	s = va_arg(valist, char *);
	dest = malloc(sizeof(*dest) * (_strlen(s) + 1));
	if (!dest)
		return (1);

	c = *s;
	i = 0;
	while (c)
	{
		l = (c >= 'a' && c <= 'z');
		u = (c >= 'A' && c <= 'Z');
		w = (l * 'a') + (u * 'A');
		if (w)
			dest[i] = (((c - w) + 13) % 26) + w;
		else
			dest[i] = c;
		i++;
		c = s[i];
	}
	dest[i] = '\0';

	string_to_buffer(dest, buffer, pos, n_printed);
	free(dest);

	return (0);
}
