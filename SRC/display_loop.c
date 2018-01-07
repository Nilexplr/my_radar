/*
** EPITECH PROJECT, 2018
** display_loop.c
** File description:
** loop fuction
*/

#include "my.h"
#include "struct.h"

item_t *prepare_game(int ac, char **av)
{
	char **map = define_map(ac, av);
	item_t *all = init_item();

	for (int i = 0; map[i] != NULL; i++) {
		if (map[i][0] = 'A')
			add_plane(all->plane, map[i]);
		if (map[i][0] = 'T')
			add_tower(all->tower, map[i]);
		if (map[i][0] = 'D')
			add_area(all->area, map[i]);
	}
	return (all);
}

void game_loop(int ac, char **av)
{
	item_t *all = prepare_game(ac, av);

	for (plane_t *it = all->plane->next; it != NULL; it = it->next)
		printf("%d", it->dep_x);
}
