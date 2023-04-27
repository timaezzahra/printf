#include "main.h"

/**
  * get_specifier - find the format
  * @s: the format string
  * Return: the number of bytes printed
  */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"u", print_unsigned},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa},
		{"X", print_HEXA},
		{"p", print_adress},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
  * get_print_func - finds the format function
  * @s: the format string
  * @ap: par
  * @params: the parameters struct
  * Return: if flag was valid
  */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
  * get_flag - finds the flag function
  * @s: the format string
  * @params: the parameters
  * Return: if flag was valid
  */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
	}
	return (i);
}

/**
  * get_width - get the widthof the format string
  * @s: the format string
  * @params: the parameters
  * @ap: the argument pointer
  * Return: pointer
  */

char *get_width(char *s, params_t *params, va_list ap)
{
	int l = 0;

	if (*s == '*')
	{
		l = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			l = l * 10 + (*s++ - '0');
	}
	params->width = l;
	return (s);
}
