/*
** EPITECH PROJECT, 2017
** struct_function.c
** File description:
** function for full up the structures
*/

#include "my.h"
#include "struct.h"

void add_plane(plane_t *plane, char *s)
{
	plane_t *new = malloc(sizeof(new));
	char **tab = my_str_to_word_array(s);

	new->dep_x = my_getnbr(tab[1]);
	new->dep_y = my_getnbr(tab[2]);
	new->arr_x = my_getnbr(tab[3]);
	new->arr_y = my_getnbr(tab[4]);
	new->speed = my_getnbr(tab[5]);
	new->delay = my_getnbr(tab[6]);
	new->display = 1;
	plane->next = new;
	new->next = NULL;
}

void add_tower(tower_t *tower, char *s)
{
	tower_t *new = malloc(sizeof(new));
	char **tab = my_str_to_word_array(s);

	new->tow_x = my_getnbr(tab[1]);
	new->tow_y = my_getnbr(tab[2]);
	new->radius = my_getnbr(tab[3]);
	new->display = 1;
	tower->next = new;
	new->next = NULL;
}

int count_word(char **tab)
{
	int count = 0;

	for (int i = 0; tab[i] != NULL; i++)
		count++;
	return (count);
}

int *tab_to_int(char **tab)
{
	int *array = malloc(sizeof(int) * count_word(tab) + 1);
	int i = 1;

	while (tab[i] != NULL) {
		array[i - 1] = my_getnbr(tab[i]);
		i++;
	}
	array[i - 1] = NULL;
	return (array);
}

void add_area(area_t *area, char *s)
{
	area_t *new = malloc(sizeof(new));
	char **tab = my_str_to_word_array(s);
	int *array = tab_to_int(tab);

	new->coord = malloc(sizeof(*array));
	for (int i = 0; array[i] != NULL; i++)
		new->coord[i] = array[i];
	new->display = 1;
	area->next = new;
	new->next = NULL;
}
