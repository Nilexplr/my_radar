/*
** EPITECH PROJECT, 2017
** disp ptr arg
** File description:
** disp ptr arg
*/

#include "my.h"
#include <stdarg.h>

void disp_p(va_list ap)
{
	my_putstr("0x");
	my_putnbr_base(va_arg(ap, long), "0123456789abcdef");
}

int zero_case(char *s, int i)
{
	int j = 0;

	while (s[i] == ' ') {
		i++;
		j++;
		if (s[i] == '\0')
			return (j - 1);
	}
	return (j);
}

void display_s(char s)
{
	if (s != '%')
		my_putchar(s);
}

int display_l(char *s, int i)
{
	int j = 0;

	if (s[i] == 'h' || s[i] == 'l') {
		i++;
		j = zero_case(s, i);
		if (s[i + j] == 'd')
			return (1);
	}
	return (0);
}
