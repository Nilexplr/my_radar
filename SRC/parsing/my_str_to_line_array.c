/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** take a string as param and convert it to tab **
*/

#include <stdlib.h>

static int my_linelen(char *str, int nb)
{
	int i = 1;

	while (str[nb + i] != '\0' && str[nb + i] != '\n') {
		i++;
	}
	return (i);
}

char **my_str_to_line_array(char *str, int number_line)
{
	int j = 0;
	int i = 0;
	int k = 0;
	char **tab = malloc(sizeof(char*) * (number_line + 1));

	while (k < number_line) {
		j = 0;
		tab[k] = malloc(sizeof(char) * (my_linelen(str, i) + 1));
		while (str[i] != '\0' && str[i] != '\n') {
			tab[k][j] = str[i];
			j++;
			i++;
		}
		i++;
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
