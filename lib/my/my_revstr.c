/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** rev str
*/

#include "my.h"

char *my_revstr(char *str)
{
	int i = 0;
	int n = 0;
	int memory;

	while (i < my_strlen(str))
		i++;
	i -= 1;
	while (n <= i) {
		memory = str[n];
		str[n] = str[i];
		str[i] = memory;
		n++;
		i--;
	}
	return (str);
}
