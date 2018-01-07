/*
** EPITECH PROJECT, 2017
** disp base
** File description:
** base for flags
*/

#include <stdarg.h>
#include "my.h"

void disp_o(va_list ap)
{
	my_putnbr_base(va_arg(ap, long), "01234567");
}

void disp_x(va_list ap)
{
	my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
}

void disp_x_m(va_list ap)
{
	my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
}

void disp_b(va_list ap)
{
	my_putnbr_base(va_arg(ap, unsigned int), "01");
}

void disp_s_m(va_list ap)
{
	char *str = va_arg(ap, char*);

	for (int i = 0; i < my_strlen(str); i++) {
		if (str[i] >= 127 || str[i] < 32) {
			my_putchar('\\');
			octal_base((int)(str[i]));
			i++;
		}
		if(str[i] != '\0')
			my_putchar(str[i]);
	}
}
