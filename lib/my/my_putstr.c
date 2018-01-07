/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** put str
*/

#include "my.h"

int my_putstr(char const *str)
{
	int a = 0;

	while (str[a] != '\0') {
		my_putchar(str[a]);
		a = a + 1;
	}
	return (0);
}
