#include "main.h"

/**
 * _print_char - print a character
 * @arptr : argment of pointer
 * @params: the parameter
 *
 * Return: numbers characters printed
 */

int _print_char(va_list arptr, params_t *params)
{
	char char_p = ' ';
	unsigned int pad = 1, sm = 0, ch = va_arg(arptr, int);

	if (params->minus_flag)
		sm += _putchar(ch);
	while (pad++ < params->width)
		sm += _putchar(char_p);
	if (!params->minus_flag)
		sm += _putchar(ch);
	return (sm);
}

/**
 * _print_int - print a integer
 * @arptr : argument of pointer
 * @params: the parameter
 *
 * Return: numbers  printed
 */
int _print_int(va_list arptr, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(arptr, long);
	else if (params->h_modifier)
		l = (short int)va_arg(arptr, int);
	else
		l = (int)va_arg(arptr, int);
	return (print_number(int convert(l, 10, 0, params), params));
}

/**
 * _print_string - print a string
 * @arptr : argument of pointer
 * @params: the parameter
 *
 * Return: numbers  printed
 */

int _print_string(va_list arptr, params_t *params)
{
	char *str = va_arg(arptr, char *), char_p = ' ';
	unsigned int pad = 0, sm = 0, i = 0, j;
	(void)params;

	switch ((int)(!str))
	case 1:
		str = NULL_STRING;
		j = pad = _strlen(str);
		if (params->precision < pad)
			j = pad = params->precision;
		if (params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sm += _putchar(*str++);
			else
				sm += _puts(str);
		}
		while (j++ < params->width)
			sm += _putchar(char_p);
		if (!params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sm += _putchar(*str++);
			else
				sm += _puts(str);
		}
		return (sm);
}

/**
 * _print_percent - print a string
 * @arptr : argument of pointer
 * @params: the parameter
 *
 * Return: numbers  printed
 */

int _print_percent(va_list arptr, params_t *params)
{
	(void)params;
	(void)arptr;

	return (_putchar('%'));
}

/**
 * _print_S - custom format specifier
 * @arptr : argument of pointer
 * @params: the parameter
 *
 * Return: numbers  printed
 */

int _print_S(va_list arptr, params_t *params)
{
	char *str = va_arg(arptr, char *);
	char *hexa;
	int sm = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32 || *str >= 127))
				{
				sm += _putchar('\\');
				sm += _putchar('x');
				hexa = convert(*str, 16, 0, params);
				if (!hexa[1])
				sm += _putchar('0');
				sm += _puts('hexa');
				}
				else
				{
				sm += _putchar(*str);
				}
	}
	return (sm);
}
