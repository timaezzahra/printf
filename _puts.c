#include "main.h"

/**
  * _puts - prints a string
  * @s: the string to print
  * Return: void
  */

int _puts(char *s)
{
	char *c = s;

	while (*s)
		_putchar(*s++);
	return (s - c);
}

/**
  * _putchar - write a character
  * @c: the character to print
  * Return: 1
  */

int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

