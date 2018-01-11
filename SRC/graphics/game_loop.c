/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game loop functions
*/

#include "my_radar.h"

void prepare_all(item_t *all)
{
	for (plane_t *it = all->plane->next; it != NULL; it = it->next)
		it->sprite = init_sprite_plane(it);
	for (tower_t *it = all->tower->next; it != NULL; it = it->next)
		it->sprite = init_sprite_tower(it);
	for (area_t *it = all->area->next; it != NULL; it = it->next)
		it->sprite = init_sprite_area(it);
}

sfRenderWindow *draw_all(item_t *all, sfRenderWindow *window)
{
	for (tower_t *it = all->tower->next; it != NULL; it = it->next)
		sfRenderWindow_drawCircleShape(window, it->sprite.circle, NULL);
	for (plane_t *it = all->plane->next; it != NULL; it = it->next)
		sfRenderWindow_drawRectangleShape(window, it->sprite.rect, NULL);
	for (area_t *it = all->area->next; it != NULL; it = it->next)
		sfRenderWindow_drawConvexShape(window, it->sprite.convex, NULL);
}
