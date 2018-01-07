/*
** EPITECH PROJECT, 2017
** disp stdarg
** File description:
** disp arg
*/

#include <stdarg.h>
#include "my.h"

void disp_c(va_list ap)
{
	my_putchar(va_arg(ap, int));
}

void disp_s(va_list ap)
{
	my_putstr(va_arg(ap, char*));
}

void disp_i(va_list ap)
{
	my_put_nbr(va_arg(ap, int));
}

void disp_mod(va_list ap)
{
	my_putchar('%');
}

void disp_u(va_list ap)
{
	my_put_unsigned(va_arg(ap, unsigned int));
}
