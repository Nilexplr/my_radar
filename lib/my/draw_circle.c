/*
** EPITECH PROJECT, 2017
** draw circle
** File description:
** draw circle
*/

#include "my.h"

int draw_circle(framebuffer_t *bf, sfVector2i center, int r, sfColor color)
{
	int counter;
	int point = 0;

	if (r < 0 || r > center.x || r > center.y)
		return (84);
	for (int y = center.y - r; y != center.y + r; y++) {
		counter = r*r - (y - center.y) * (y - center.y);
		point = sqrt(counter);
		for (int i = point * -1 + center.x;
		     i != point + center.x; i++)
			my_put_pixel(bf, i, y, color);
	}
	for (int x = center.x - r; x != center.x + r; x++) {
		counter = r*r - (x - center.x) * (x - center.x);
		point = sqrt(counter);
		for (int i = point * -1 + center.y ;
		     i != point + center.y ; i++)
			my_put_pixel(bf, x, i, color);
	}
	return (0);
}

int draw_border(framebuffer_t *bf, sfVector2i center, int r ,sfColor color)
{
	int counter;
	int point = 0;

	if (r < 0 || r > center.x || r > center.y)
		return (84);
	for (int y = center.y - r; y != center.y + r; y++) {
		counter = r*r - (y - center.y) * (y - center.y);
		point = sqrt(counter);
		my_put_pixel(bf, point + center.x, y, sfRed);
		my_put_pixel(bf, (-1 * point) + center.x, y, color);
	}
	for (int x = center.x - r; x != center.x + r; x++) {
		counter = r*r - (x - center.x) * (x - center.x);
		point = sqrt(counter);
		my_put_pixel(bf, x, point + center.y, sfRed);
		my_put_pixel(bf, x, (-1 * point) + center.y, color);
	}
	return (0);
}
