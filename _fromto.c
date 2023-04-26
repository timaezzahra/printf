#include "main.h"

/**
  * print_from_to - print a range
  * @start: the start
  * @stop: the end
  * @except: except
  * Return: number of bytes
  */

int print_from_to(char *start, char *stop, char *except)
{
	int sm = 0;

	while (start <= stop)
	{
		if (start != except)
			sm += _putchar(*start);
		start++;
	}
	return (sm);
}

/**
  * print_rev - string in reverse
  * @ap: ap
  * @params: the parameters
  * Return: number of bytes
  */

int print_rev(va_list ap, params_t *params)
{
	int lenth, sm = 0;
	char *s = va_arg(ap, char *);
	(void)params;

	if (s)
	{
		for (lenth = 0; *s; s++)
			lenth++;
		s--;
		for (; lenth > 0; lenth--, s--)
			sm += _putchar(*s);
	}
	return (sm);
}

/**
  * print_rot13 - a string in rot13
  * @ap: ap
  * @params: params
  * Return: bytes
  */

int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char ar[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM    nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] < 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(ar[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

