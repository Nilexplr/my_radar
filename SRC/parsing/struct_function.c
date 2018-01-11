/*
** EPITECH PROJECT, 2017
** struct_function.c
** File description:
** function for full up the structures
*/

#include "my.h"
#include "struct.h"
#include "my_radar.h"

void add_plane(plane_t *plane, char *s)
{
	plane_t *new = malloc(sizeof(plane_t));
	char **tab = my_str_to_word_array(s);

	new->dep_x = my_getnbr(tab[1]);
	new->dep_y = my_getnbr(tab[2]);
	new->arr_x = my_getnbr(tab[3]);
	new->arr_y = my_getnbr(tab[4]);
	new->speed = my_getnbr(tab[5]);
	new->delay = my_getnbr(tab[6]);
	new->display = 1;
	for ( ; plane->next != NULL; plane = plane->next);
	plane->next = new;
	new->next = NULL;
}

void add_tower(tower_t *tower, char *s)
{
	tower_t *new = malloc(sizeof(tower_t));
	char **tab = my_str_to_word_array(s);

	new->tow_x = my_getnbr(tab[1]);
	new->tow_y = my_getnbr(tab[2]);
	new->radius = my_getnbr(tab[3]);
	new->display = 1;
	for ( ; tower->next != NULL; tower = tower->next);
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
	array[i - 1] = 150;
	return (array);
}

void add_area(area_t *area, char *s)
{
	area_t *new = malloc(sizeof(area_t));
	char **tab = my_str_to_word_array(s);
	int *array = tab_to_int(tab);
	int i = 0;

	new->coord = malloc(sizeof(int) * count_word(tab));
	while (array[i] != 150) {
		new->coord[i] = array[i];
		i++;
	}
	new->coord[i] = 150;
	new->display = 1;
	for ( ; area->next != NULL; area = area->next);
	area->next = new;
	new->next = NULL;
}
