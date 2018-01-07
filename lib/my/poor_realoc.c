/*
** EPITECH PROJECT, 2018
** poor_realoc.c
** File description:
** realloc where adress change
*/

#include "my.h"

char *poor_realloc(char *s)
{
	int number = my_strlen(s);
	char *dest = malloc(sizeof(char) * number + 1);

	dest = my_strcpy(s, dest);
	free(s);
	return (dest);
}
