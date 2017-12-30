/*
** EPITECH PROJECT, 2017
** printf
** File description:
** my_printf
*/

#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int define_flag(char flag, char *str_flag)
{
	int j = 0;

	for (int i = 1; str_flag[i] != '\0'; i++) {
		if (str_flag[i] == flag)
			return (i);
	}
	return (0);
}

int watch_next(char *s, int i)
{
	int j = 0;
	i++;

	j = display_l(s, i);
	if (s[i] == '#') {
		i++;
		j = zero_case(s, i);
		if (s[j + i] == 'o')
			my_putchar('0');
		if (s[j + i] == 'x' || s[i] == 'X')
			my_putstr("0x");
		else
			return (j - 1);
		return (j + 1);
	}
	return (j);
}

void init(va_list ap)
{
	my_putchar('%');
}

void no_flag(char s, int counter)
{
	if (counter == 0)
		my_putchar(s);
}

int my_printf(char *s, ...)
{
	va_list ap;
	void (*call[14])(va_list) = {init, disp_c, disp_s, disp_i, disp_i,
				     disp_mod, disp_mod, disp_o, disp_x,
				     disp_X, disp_u, disp_b, disp_S, disp_p };
	char flags[14] = " csid %oxXubSp";
	int counter;

	va_start(ap, s);
	for ( int i = 0; i < my_strlen(s); i++) {
		display_s(s[i]);
		if (s[i] == '%') {
			i += zero_case(s, i + 1);
			i += watch_next(s, i);
			counter = define_flag(s[i + 1], flags);
			call[counter](ap);
			no_flag(s[i + 1], counter);
			i++;
		}
	}
	va_end(ap);
	return (0);
}
