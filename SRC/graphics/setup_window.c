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

void prepare(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture)
{
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_setFramerateLimit(window, 60);
}
