#include "main.h"

/**
  * print_hexa - print unsigned hexadecimal number in lowcaser
  * @arptr: argument pointer
  * @params: parameters
  *
  * Return: bytes printed
  */

int print_hexa(va_list arptr, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(arptr, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int) va_arg(arptr, unsigned int);
	else
		l = (unsigned int)va_arg(arptr, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsigne = 1;
	return (c += _print_number(str, params));
}

/**
 * print_HEXA - print unsigned hexadecimal number in uppercase
 * @arptr: argument pointer
 * @params: parameters
 *
 * Return: bytes printed
 */
int print_HEXA(va_list arptr, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(arptr, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(arptr, unsigned int);
	else
		 l = (unsigned int)va_arg(arptr, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsigne = 1;
	return (c += _print_number(str, params));
}

/**
  * print_binary - print unsigned binary num
  * @arptr: argument pointer
  * @params: parameters
  *
  * Return: bytes printed
  */
int print_binary(va_list arptr, params_t *params)
{
	unsigned int n = va_arg(arptr, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsigne = 1;
	return (c += _print_number(str, params));
			}
/**
 * print_octal - print unsigned octal num
 * @arptr: argument pointer
 * @params: parameters
 *
 * Return: bytes printed
 */
int print_octal(va_list arptr, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
	l = (unsigned long)va_arg(arptr, unsigned long);
	else if (params->h_modifier)
	l = (unsigned short int)va_arg(arptr, unsigned int);
	else
	l = (unsigned int)va_arg(arptr, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if  (params->hashtag_flag && l)
		*--str = '0';
	params->unsigne = 1;
	return (c += _print_number(str, params));
			}
