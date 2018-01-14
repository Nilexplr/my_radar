/*
** EPITECH PROJECT, 2018
** setup_destroye.c
** File description:
** destroy functions
*/

#include "my_radar.h"

void *destroy_plane(plane_t *plane)
{
	sfTexture_destroy(plane->sprite.texture);
	sfRectangleShape_destroy(plane->sprite.rect);
	plane->prec->next = plane->next;
	plane->next->prec = plane->prec;
	free(plane);
}
