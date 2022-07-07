#include "main.h"

/**
 * storev - get a reversed copy of a string
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 * @spec: specifier flags
 *
 * Return: Always 0
 */
int storev(va_list valist, char *buffer, int *pos, int *n_printed, char *spec)
{
	char *_s = va_arg(valist, char *);
	char *s = _strdup(_s);
	char temp;
	int i, len;

	(void) spec;

	if (!s)
		return (1);

	for (len = 0; s[len] != '\0'; len++)
		;

	for (i = len - 1; i >= len / 2; i--)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}

	string_to_buffer(s, buffer, pos, n_printed);
	free(s);

	return (0);
}
