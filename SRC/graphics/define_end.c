/*
** EPITECH PROJECT, 2018
** define end.c
** File description:
** define end function
*/

#include "my_radar.h"

int define_end(item_t *all)
{
	sfVector2f end;

	for (plane_t *it = all->plane->next; it != all->plane; it = it->next) {
		end = sfRectangleShape_getPosition(it->sprite.rect);
		if (end.x == it->sprite.end.x && end.y == it->sprite.end.y)
			destroy_plane(it);
	}
	if (all->plane->next == all->plane)
		return (1);
	return (0);
}
