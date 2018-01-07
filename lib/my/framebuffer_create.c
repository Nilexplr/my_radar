/*
** EPITECH PROJECT, 2017
** framebuffer create
** File description:
** framebuffer create function
*/

#include "my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *buff;

	buff = malloc(sizeof(*buff));
	if (buff == NULL)
		return (NULL);
	buff->width = width;
	buff->height = height;
	buff->pixels = malloc(width * height * 4);
	if (buff->pixels == NULL)
		return (NULL);
	return (buff);
}
