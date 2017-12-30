/*
** EPITECH PROJECT, 2017
** draw square
** File description:
** draw square function
*/

#include "sflm.h"

void draw_square(framebuffer_t *framebuffer, sfVector2i pos, sfVector2i size, sfColor color)
{
	int i = pos.y;
	int j;

	while (i < size.y)
	{
		j = pos.x;
		while (j < size.x)
		{
			my_put_pixel(framebuffer, j , i, color);
				j++;
		}
		i++;
	}
}
