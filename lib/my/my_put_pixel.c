/*
** EPITECH PROJECT, 2017
** put pixels
** File description:
** put pixels function
*/

#include "sflm.h"

int my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y,
		  sfColor color)
{
	if (x > buffer->width || y > buffer->height || x < 0 || y < 0)
		return (0);
	int n = ((y * buffer->width + x) * 4);

	buffer->pixels[n] = color.r;
	buffer->pixels[n + 1] = color.g;
	buffer->pixels[n + 2] = color.b;
	buffer->pixels[n + 3] = color.a;
	return (0);
}
