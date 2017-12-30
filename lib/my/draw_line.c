/*
** EPITECH PROJECT, 2017
** Draw line
** File description:
** draw line
*/

#include "sflm.h"

int draw_vertical(framebuffer_t *fb, sfVector2i point_a, sfVector2i point_b,
		  sfColor color)
{
	while (point_a.y != point_b.y) {
		my_put_pixel(fb, point_a.x, point_a.y, color);
		point_a.y++;
	}
	return (0);

}
int absolute(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

int display_line(framebuffer_t *framebuffer, sfVector2i point_a,
		 sfVector2i point_b, sfColor color)
{
	float axis;
	float ordo;

	if (point_a.x - point_b.x == 0) {
		draw_vertical(framebuffer, point_a, point_b, color);
		return (0);
	}
	axis = (float)(point_a.y - point_b.y) / (point_a.x - point_b.x);
	ordo = (float)(point_a.y - axis * point_a.x);
	if (absolute(point_a.x - point_b.x)  >= absolute(point_a.y - point_b.y))
		for(int i = point_a.x; i <= point_b.x; i++) {
			my_put_pixel(framebuffer, i, (int)(i * axis + ordo),
				     color);
		}
	if (absolute(point_a.x - point_b.x) < absolute(point_a.y - point_b.y))
		for(int i = point_a.y; i <= point_b.y; i++) {
			my_put_pixel(framebuffer, (int)((i - ordo) / axis), i ,
				     color);
		}
	return (0);
}

int draw_line(framebuffer_t *framebuffer, sfVector2i point_a,
	      sfVector2i point_b, sfColor color)
{
	if (absolute(point_a.x - point_b.x)  >=
	    absolute(point_a.y - point_b.y)) {
		if(point_a.x > point_b.x)
			display_line(framebuffer, point_b, point_a, color);
		else
			display_line(framebuffer, point_a, point_b, color);
	}
	if (absolute(point_a.x - point_b.x) < absolute(point_a.y - point_b.y)) {
		if(point_a.y > point_b.y)
			display_line(framebuffer, point_b, point_a, color);
		else
			display_line(framebuffer, point_a, point_b, color);
	}
	return (0);
}
