/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *src)
{
	int i = 0;
	int len = my_strlen(src);
	char *str = malloc(sizeof(char) * (len + 1));

	if (str == 0)
		return (0);
	while (i < len) {
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
