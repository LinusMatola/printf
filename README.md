# printf

printf is a project that sends formatted output to stdout. It is designed to replicate the functionality of the C standard library function printf.

## Requirements

* Allowed editors: vi, vim, emacs
* All files are compiled on Ubuntu 14.04 LTS
* Programs and functions are compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Code should use the Betty style. It is checked using betty-style.pl and betty-doc.pl
* The use of global variables is prohibited
* No more than 5 functions per file
* The prototypes of all functions should be included in a header file called holberton.h
* All header files should be include guarded

## Prototype

```bash
int _printf(const char *format, ...);
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c
```

## Usage

```bash
int _printf(const char *format, ...);
```

## Format Specifiers

### Supported Types

| Type  | Output |
|:-----:|-----------|
| c       | Single character |
| s       | String of characters |
| d or i  | Signed decimal integer |
| u       | Unsigned decimal integer |
| b       | Unsigned binary |
| o       | Unsigned octal |
| x       | Unsigned hexadecimal (lowercase) |
| X       | Unsigned hexadecimal (uppercase) |
| p       | Pointer address |
| S       | Print a string of characters, with hexadecimal ASCII value of non-printable characters |
| r       | Print a string of characters in reverse |
| R       | Print a string of characters with rot13 substitution |
| %       | A % followed by another % will write just one % |

### Supported Flags

| Flags   | Description |
|:------: |-------------|
| +	  | Forces to precede the result with (+ or -) |
| (space) | If no sign is written, insert a blank space before the value |
| #	  | Used with b, o, x, or X specifiers, prints 0, 0, 0x, or 0X respectively for values other than zero |

### Supported Length

| Length | d i | u o x X |
|:------:|:---:|---------|
| (none) | int | unsigned int |
| h | short int | unsigned short int |
| l | long int | unsigned long int |

### Return Value

Return the number of characters written, excluding the terminating null character to send the string.

## Examples

```c
$ cat main.c
#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%y]\n");
    printf("Unknown:[%y]\n");
    return (0);
}
$ gcc -Wall -Wextra -Werror -pedantic -Wno-format *.c
$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%y]
Unknown:[%y]
```

## Authors

[Ben Cook](https://github.com/benjamesian)

[Brent Muha](https://github.com/bmuha1)
