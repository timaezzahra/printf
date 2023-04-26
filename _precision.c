#include "main.h"

/**
  * get_precision - gets the precision
  * @p: the format string
  * @params: the parameters struct
  * @ap: the argument pointer
  * Return: pointer
  */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int l = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		l = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			l = l * 10 + (*p++ - '0');
	}
	params->precision = l;
	return (p);
}
