#include "main.h"

/**
 * convert - a function to convert
 * @num: number
 * @base: base
 * @flags: flags arguments
 * @params:  parameters
 *
 * Return: string
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *ar; /*array*/
	static char buf[50];
	char *p; /* pointer */
	char s = 0 ; /* sign */
	unsigned long n = num;
	(void)params; /* unused variable */

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';
	}
	ar = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
		p = &buf[49];
	*p = '\0';

	do {
		*--p = ar[n % base];
		n = n / base;
	} while (n != 0);
	if (s)
		*--p = s;
	return (p);
}

/**
 * print_unsigned - print the unsigned integer numbers
 * @arptr: argument pointer
 * @params:  parameters
 *
 * Return: bytes printed
 */

int print_unsigned(va_list arptr, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(arptr, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(arptr, unsigned int);
	else
		l = (unsigned int)va_arg(arptr, unsigned int);
	params->unsigne = l;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * print_adress - print the adress
 * @arptr: argument pointer
 * @params:  parameters
 *
 * Return: bytes printed
 */

int print_adress(va_list arptr, params_t *params)
{
	unsigned long int n = va_arg(arptr, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
