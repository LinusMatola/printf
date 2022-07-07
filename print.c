#include <unistd.h>

/**
 * print - print a string
 * @buffer: string to print
 * @n: number of bytes to print
 *
 * Return: On success n.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print(char *buffer, size_t n)
{
	return (write(1, buffer, n));
}
