#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#define OUTPUT_BUF_SIZE    1024
#define BUF_FLUSH -1
#define NULL_STRING "null"
#define CONVERT_LOWERCASE      1
#define CONVERT_UNSIGNED       2
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
  * struct parameters - parameters struct
  * @unsigne: flag if unsigned value
  * @plus_flag: if plus flag specified
  * @space_flag: if space flag specified
  * @zero_flag: if 0 flag is specified
  * @hashtag_flag: if hashtag is specified
  * @minus_flag: if it's specified
  * @width: if width is specified
  * @precision: if it's specified
  * @h_modifier: if it's specified
  * @l_modifier: if it's specified
  */

typedef struct parameters
{
	unsigned int unsigne        : 1;
	unsigned int plus_flag      : 1;
	unsigned int space_flag     : 1;
	unsigned int zero_flag      : 1;
	unsigned int hashtag_flag   : 1;
	unsigned int minus_flag     : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier     : 1;
	unsigned int l_modifier     : 1;
} params_t;

/**
  * struct specifier - Struct token
  * @specifier: format token
  * @f: the function
  */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *s);
int _putchar(int c);

/*print_funcs.c*/
int print_char(va_list arptr, params_t *params);
int print_int(va_list arptr, params_t *params);
int print_string(va_list arptr, params_t *params);
int print_percent(va_list arptr, params_t *params);
int print_S(va_list arptr, params_t *params);


int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/*nums.c*/
char *convert(long int num, int base, int flags; params_t *params);
int print_unsigned(va_list arptr,params_t *params);
int print_adress(va_list arptr, params_t *params);


/*convert_nums.c*/
int print_hexa(va_list arptr, params_t *params);
int print_HEXA(va_list arptr, params_t *params);
int print_binary(va_list arptr, params_t *params);
int print_octal(va_list arptr, params_t *params);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_nums.c*/
int _isdigit(int char);
int _strlen(char *s);
int _print_number(char *str, params_t *params);
int _print_number_right_shift(char *str, params_t *params);
int _print_number_left_shift(char *str, params_t *params);


char *get_precision(char *p, params_t *params, va_list ap);
void init_params(params_t *params, va_list ap);
int _print(const char *format, ...);

#endif
