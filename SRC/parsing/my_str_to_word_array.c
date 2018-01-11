/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** take a string as param and convert it to tab **
*/

#include "my.h"

int number_word(char *str)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' &&
		    (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

char **my_str_to_word_array(char *str)
{
	char **tab = malloc(sizeof(char*) * number_word(str) + 1);
	int j = 0;
	int i = 0;
	int k = 0;

	while (str[i] != '\0') {
		tab[k] = malloc(sizeof(char) * my_strlen(str));
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		j = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
			tab[k][j] = str[i];
			i++;
			j++;
		}
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
