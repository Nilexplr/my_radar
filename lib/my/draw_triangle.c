/*
** EPITECH PROJECT, 2017
** draw triangle
** File description:
** triangle
*/
#include "sflm.h"

int draw_triangle(framebuffer_t *fb,
		  sfVector2i pa, sfVector2i pb, sfVector2i pc)
{
	sfColor array[5] = {sfGreen, sfBlue, sfWhite, sfRed, sfBlack};

	draw_line(fb, pa, pb, array[rand() % 5]);
	draw_line(fb, pa, pc, array[rand() % 5]);
	draw_line(fb, pb, pc, array[rand() % 5]);
}
