/*
** EPITECH PROJECT, 2018
** setup_mouvement.c
** File description:
** setup mouvement function
*/

#include "my_radar.h"

void mouvement_all(item_t *all)
{
	for (plane_t *it = all->plane->next; it != all->plane; it = it->next)
		sfRectangleShape_move(it->sprite.rect, it->sprite.mouvement);
}

sfVector2f init_mouvement(sfVector2f dep, sfVector2f arr)
{
	sfVector2f mouvement;

	if (dep.x == arr.x) {
		mouvement.x = 0;
		if (dep.y > arr.y)
			mouvement.y = -1;
		if (dep.y < arr.y)
			mouvement.y = 1;
		return (mouvement);
	}
	if (dep.x < arr.x) {
		mouvement.x = 1;
		mouvement.y = (dep.y - arr.y) / (dep.x - arr.x);
	}
	if (dep.x > arr.x) {
		mouvement.x = -1;
		mouvement.y = -(dep.y - arr.y) / (dep.x - arr.x);
	}
	return (mouvement);
}

float calcul_up(sfVector2f dep, sfVector2f arr, float rotate)
{
	if (dep.x > arr.x)
		rotate = -rotate;
	else
		rotate = rotate;
	return (rotate);
}

float calcul_down(sfVector2f dep, sfVector2f arr, float rotate, int nb)
{
	if (dep.x < arr.x )
		rotate = nb + rotate;
	if (dep.x > arr.x)
		rotate = nb - rotate;
	return (rotate);
}

float init_rotate(sfVector2f dep, sfVector2f arr)
{
	float x = (float)(abs(dep.x - arr.x));
	float y = (float)(abs(dep.y - arr.y));
	float rotate = atanf((x / y)) * 180.0 / M_PI;

	if (dep.x == arr.x) {
		if (dep.y > arr.y)
			rotate = 0;
		if (dep.y < arr.y)
			rotate = 180;
		return (rotate);
	}
	if (dep.y >= arr.y) {
		if (abs((dep.y - arr.y)) / abs((dep.x - arr.x)) >= 1)
			rotate = calcul_up(dep, arr, rotate);
		else
			rotate = calcul_down(dep, arr, rotate, 0);
	}
	if (dep.y < arr.y) {
		if (abs((dep.y - arr.y)) / abs((dep.x - arr.x)) >= 1)
			rotate = 180 + calcul_up(arr, dep, rotate);
		else
			rotate = calcul_down(arr, dep, rotate, 180);
	}
	return (rotate);
}
