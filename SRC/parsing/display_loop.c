/*
** EPITECH PROJECT, 2018
** display_loop.c
** File description:
** loop fuction
*/

#include "my.h"
#include "struct.h"
#include "my_radar.h"

item_t *prepare_game(int ac, char **av)
{
	char **map = define_map(ac, av);
	item_t *all = init_item();

	for (int i = 0; map[i] != NULL; i++) {
		if (map[i][0] == 'A')
			add_plane(all->plane, map[i]);
		if (map[i][0] == 'T')
			add_tower(all->tower, map[i]);
		if (map[i][0] == 'D')
			add_area(all->area, map[i]);
	}
	open_window(all);
	return (all);
}

void game_loop(int ac, char **av)
{
	item_t *all = prepare_game(ac, av);

	for (plane_t *it = all->plane->next; it != NULL; it = it->next) {
		printf("dep x %d ", it->dep_x);
		printf("dep y %d ", it->dep_y);
		printf("arr x %d ", it->arr_x);
		printf("arr y %d ", it->arr_y);
		printf("speed %d ", it->speed);
		printf("delay %d ", it->delay);
		printf("display %d\n", it->display);
	}
	for (tower_t *it = all->tower->next; it != NULL; it = it->next) {
		printf("tow x %d ", it->tow_x);
		printf("tow y %d ", it->tow_y);
		printf("radius %d ", it->radius);
		printf("display %d\n", it->display);
	}
	for (area_t *it = all->area->next; it != NULL; it = it->next) {
		for (int i = 0; it->coord[i] != 150; i++)
			printf("coord %d %d ",i , it->coord[i]);
		printf("display %d\n", it->display);
	}
}
