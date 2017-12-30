/*
** EPITECH PROJECT, 2017
** clear framebuffer
** File description:
** clean framebuffer
*/
#include "sflm.h"

framebuffer_t *fb_clean(framebuffer_t *fb, unsigned int width,
				  unsigned int height)
{
	fb->width = width;
	fb->height = height;
	for (unsigned int i = 0 ;  i < width * height * 4 ; i += 4) {
		fb->pixels[i] = 0;
		fb->pixels[i + 1] = 0;
		fb->pixels[i + 2] = 0;
		fb->pixels[i + 3] = 255;
	}
	return (fb);
}


