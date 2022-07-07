#include "main.h"

/**
 * stoa - Return the next string in va_list
 * @valist: list with next argument
 * @buffer: character buffer for printing
 * @pos: position in the buffer
 * @n_printed: number of printable characters
 * @spec: specificer flags
 *
 * Return: Always 0
 */
int stoa(va_list valist, char *buffer, int *pos, int *n_printed, char *spec)
{
	char *string = va_arg(valist, char *);

	(void) spec;

	if (!string)
		string = "(null)";

	string_to_buffer(string, buffer, pos, n_printed);

	return (0);
}
