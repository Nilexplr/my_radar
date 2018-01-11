/*
** EPITECH PROJECT, 2017
** setup_window.c
** File description:
** setup function
*/

#include <SFML/Window/Event.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include "my_radar.h"

void refresh(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfRenderWindow_display(window);
}

void prepare(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture)
{
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_setFramerateLimit(window, 60);
}

void destroy(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture)
{
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	sfRenderWindow_destroy(window);
}

/* void play_cube(void) */
/* { */
/* 	int array[800 * 600]; */
/* 	sfVideoMode mode = {800, 600, 32}; */
/* 	sfRenderWindow *window; */
/* 	sfTexture *texture = sfTexture_create(800, 600);; */
/* 	sfSprite *sprite = sfSprite_create(); */
/* 	framebuffer_t *framebuffer = framebuffer_create(800, 600); */

/* 	window = sfRenderWindow_create(mode, "SFML window", sfClose, NULL); */
/* 	if (!window) */
/* 		return; */
/* 	prepare(window, sprite, texture); */
/* 	game_cube(window, sprite, texture, framebuffer); */
/* 	destroy(window, sprite, texture); */
/* } */
