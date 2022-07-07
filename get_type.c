#include "main.h"

/**
 * get_type - Determine data type and function to convert to string
 * @s: The string
 *
 * Return: Pointer to function to convert to string
 */
int (*get_type(char s))(va_list, char *, int *, int *, char *)
{
	spec_t specs[] = {
		{'c', ctoa},
		{'d', itoa},
		{'i', itoa},
		{'s', stoa},
		{'%', pcttoa},
		{'R', rot13},
		{'r', storev},
		{'b', btoa},
		{'u', utoa},
		{'o', otoa},
		{'x', xtoa},
		{'X', Xtoa},
		{'S', Stoa},
		{'p', ptoa},
		{'\0', NULL}
	};
	int i = 0;

	while (specs[i].s)
	{
		if (specs[i].s == s)
			return (specs[i].f);
		i++;
	}

	return (NULL);
}
