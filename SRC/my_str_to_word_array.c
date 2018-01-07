/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** take a string as param and convert it to tab **
*/

#include "my.h"

int len_word(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') {
		if (my_str_isnum(str) == 0 && my_str_isalpha(str) == 0)
			count++;
		i++;
	}
	return (count);
}

int number_word(char *str)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ' &&
		    (str[i + 1] == ' ' || str[i + 1] == '\t'))
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
		tab[k] = malloc(sizeof(char) * len_word(str));
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		j = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
			tab[k][j] = str[i];
			i++;
			j++;
		}
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
