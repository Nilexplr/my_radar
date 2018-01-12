/*
** EPITECH PROJECT, 2017
** init_struct.c
** File description:
** function init the structures
*/

#include "my.h"
#include "struct.h"
#include "my_radar.h"

plane_t *init_plane(void)
{
	plane_t *plane = malloc(sizeof(plane_t));
	if (plane != NULL) {
		plane->dep_x = 0;
		plane->dep_y = 0;
		plane->arr_x = 1;
		plane->arr_y = 0;
		plane->speed = 0;
		plane->delay = 0;
		plane->display = 0;
		plane->next = plane;
		plane->prec = plane;
	}
	return (plane);
}

tower_t *init_tower(void)
{
	tower_t *tower = malloc(sizeof(tower_t));
	if (tower != NULL) {
		tower->tow_x = 0;
		tower->tow_y = 0;
		tower->radius = 0;
		tower->display = 0;
		tower->next = NULL;
	}
	return (tower);
}

area_t *init_area(void)
{
	area_t *area = malloc(sizeof(area_t));
	if (area != NULL) {
		area->coord = NULL;
		area->display = 0;
		area->nb_coord = 0;
		area->next = NULL;
	}
	return (area);
}

item_t *init_item(void)
{
	item_t *all = malloc(sizeof(item_t));

	if (all != NULL) {
		all->plane = init_plane();
		all->tower = init_tower();
		all->area = init_area();
	}
	return (all);
}
