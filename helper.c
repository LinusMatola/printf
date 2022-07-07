#include "main.h"

/**
 * validate_spec - check if a specifier is valid for printf
 * @spec: specifier
 *
 * Return: 1 if specifier is valid, else 0
 */
char validate_spec(char *spec)
{
	int i;
	char *specifiers = "cs%dibuoxXSprR";

	if (!spec || !spec[0])
		return ('\0');

	for (i = 0; spec[i]; i++)
		;
	i--;

	if (!contains(specifiers, spec[i]))
		return ('\0');

	return (spec[i]);
}

/**
 * contains - check if a string contains a character
 * @s: string
 * @c: character
 *
 * Return: 1 if character found in string, else 0
 */
int contains(char *s, char c)
{
	int i;

	if (!s)
		return (0);

	for (i = 0; s[i]; i++)
		if (s[i] == c)
			return (1);

	return (s[i] == c);
}

/**
 * get_substring_length - count characters until start of character specifier
 * @s: pointer to initial character in string
 *
 * Return: number of characters from initial character to character specifier
 */
int get_substring_length(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0' && s[len] != '%'; len++)
		;

	return (len);
}

/**
 * get_specifier_length - get number of characters in a character specifier
 * @s: first character in character specifier
 *
 * Return: On success number of characters in character specifier
 * On error (invalid specifier), 0 is returned.
 */
int get_specifier_length(const char *s)
{
	int i;
	char *specs = "cs%dibuoxXSprR";

	if (!s)
		return (0);

	i = 1;
	while (s[i] && !contains(specs, s[i]))
		i++;

	if (!contains(specs, s[i]))
		return (0);

	return (i + 1);
}

/**
 * get_printable_length - get printable length
 * @s: string to print
 *
 * Return: printable length
 */
int get_printable_length(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}
