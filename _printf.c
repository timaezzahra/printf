#include "main.h"

/**
  * _printf - a function that produces output according to a format.
  * @format: format string
  * Return: the number of characters printed
  */

int _printf(const char *format, ...)
{
	int sm = 0;
	va_list ap;
	char *m, *strt;
	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (m = (char *)format; *m; m++)
	{
		init_params(&params, ap);
		if (*m != '%')
		{
			sm += _putchar(*m);
			continue;
		}
		strt = m;
		m++;
		while (get_flag(m, &params))
		{
			m++;
		}
		m = get_width(m, &params, ap);
		m = get_precision(m, &params, ap);
		if (get_modifier(m, &params))
			m++;
		if (!get_specifier(m))
			sm += print_from_to(strt, m,
					params.l_modifier || params.h_modifier ? m - 1 : 0);
		else
			sm += get_print_func(m, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sm);
}

