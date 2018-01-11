/*
** EPITECH PROJECT, 2018
** open_window.c
** File description:
** open_window function
*/

#include "my_radar.h"
#include "my.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
	while (sfRenderWindow_pollEvent(window, &event))
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
}

sfRenderWindow *my_window_create(void)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = 1000;
	mode.height = 1000;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My Radar", sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

void open_window(item_t *all)
{
	sfEvent event;
	sfRenderWindow *window = my_window_create();
	background_t back = init_back();

	prepare(window, back.sprite, back.texture);
	prepare_all(all);
	while (sfRenderWindow_isOpen(window)) {
		close_window(window, event);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, back.sprite, NULL);
		draw_all(all, window);
		sfRenderWindow_display(window);
	}
}
