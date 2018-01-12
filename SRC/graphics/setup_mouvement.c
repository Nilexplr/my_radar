/*
** EPITECH PROJECT, 2018
** setup_mouvement.c
** File description:
** setup mouvement function
*/

#include "my_radar.h"

void mouvement_all(item_t *all, sfRenderWindow *window)
{
	for (plane_t *it = all->plane->next; it != NULL; it = it->next)
		sfRectangleShape_move(it->sprite.rect, it->sprite.mouvement);

}

sfVector2f init_mouvement(sfVector2f dep, sfVector2f arr)
{
	sfVector2f mouvement;

	if (dep.x <= arr.x) {
		mouvement.x = 1;
		mouvement.y = (dep.y - arr.y) / (dep.x - arr.x);
	}
	if (dep.x > arr.x) {
		mouvement.x = -1;
		mouvement.y = -(dep.y - arr.y) / (dep.x - arr.x);
	}
	return (mouvement);
}
