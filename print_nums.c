#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @char : charcter to check
 *
 * Return: 1 if digit, 0 if not
 */

int _isdigit(int char)
{
	return (char >= '0' && chat <= '9');
}

/**
 * _strlen - the lenght of a string
 * @s : the string to check his length
 *
 * Return: int length of the srting
 */

int _strlen(char *s)
{
	int i;

	while (*s++)
		i++;
	return (i);
}

/**
 * _print_number - print a number
 * @str : the base number as a string
 * @params: the parameter
 *
 * Return: printed characters
 */
int print_numbers(char *str, params_t *params)
{
	unsigned int i = strlen(str);
	int negative = (!params->unsign && *str == '-');

	if (params->precision && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		i--;
}

	if (params->precision != UNIT_MAX)
while (i++ < params->precision)
	*--str = '-';
if (!params->minus_flag)
	return (print_number_right_shift(str, params));
	else
	return (print_number_left_shift(str, params));
}

/**
 * _print_number_right_shift - print a number
 * @str : the base number as a string
 * @params: the parameter
 *
 * Return: printed characters
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, negative, negative2, i = _strlen(str);
	char char_p = '0';

	if (params->zero_flag && !params->minus_flag)
		char_p = '0';
	nega = nega2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		nega = 0;
	if ((params->plus_flag && !nega2) || (params->plus_flag && params->space_flag && !nega2))
		i++;
	if (nega && char_p == '0')
		n += _putchar('-');

	if ((params->plus_flag && !nega2 && char_p == '0' !params->unsign)
			n += _putchar('+');
			else if (!params->plus_flag && params->space_flag && !nega2 && !params->unsign && params->zero_flag)
			n += _putchar(' ');
			while (i++ < params->width)
			n += _putchar (char_p);
			if (nega && char_p == ' ')
			n += _putchar('-');
			if (params->plus_flag && !nega2 && char_p == ' ' && !params->unsign)
			n += _putchar('+');
			else if (!params->plus_flag && params->space_flag && !nega2 && !params->unsign && !params->zero_flag)
			n += _putchar(' ');
			n += _putchar(str);
			return (n);
}

/**
 * _print_number_left_shift - print a number
 * @str : the base number as a string
 * @params: the parameter
 *
 * Return: printed characters
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, nega, nega2, i = _strlen(str);
	char char_p = ' ';

	if ((params->zero_flag && !params->minus_flag)
			char_p = '0';
			nega = nega2 = (!params->unsign && *str == '-');
			if (nega && i < params->width && char_p == '0' && !params->minus_flag)
			str++;
			else
			nega = 0;

			if ((params->plus_flag && !nega2 && !params->unsign)
				n += _putchar('+'), i++;
				else if (params->space_flag && !nega2 && !params->unsign)
				n += _putchar(' '), i++;
				n += _putchar(str);
				while (i++ < params->width)
				n += _putchar(char_p);
				return (n);
}
