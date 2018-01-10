/*
** This file will be useful to test collision between two rectangles.
** Modify it to test collision between other shapes.
*/

#include <SFML/Graphics.h>
#include "struct.h"

void my_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

sfRectangleShape *create_rectangle_entity(sfVector2f size, sfColor color)
{
	sfRectangleShape *rec = sfRectangleShape_create();
	sfVector2f origin = {size.x / 2, size.y / 2};

	sfRectangleShape_setSize(rec, size);
	sfRectangleShape_setFillColor(rec, color);
	sfRectangleShape_setOrigin(rec, origin);
	return (rec);
}

sfConvexShape *create_convex(sfVector2f size, sfColor color)
{
	
}

sfBool check_rectangle_collision(sfRectangleShape *rect1, sfRectangleShape *rect2)
{
	sfVector2f pos1 = sfRectangleShape_getPosition(rect1);
	sfVector2f pos1a = {pos1.x + 100, pos1.y + 100};
	sfVector2f pos2 = sfRectangleShape_getPosition(rect2);
	sfVector2f pos2a = {pos2.x + 100, pos2.y + 100};

	if ( pos1.x <= pos2a.x && pos1.y <= pos2.y &&
		pos1a.x >= pos2.x && pos1a.y >= pos2.y)
		return (sfTrue);
	return (sfFalse);
}

sfRenderWindow *my_window_create()
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = 1000;
	mode.height = 1000;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My Radar", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

transformed_shape_t *to_transformed_shape(sfConvexShape *shape)
{
	sfTransform transform = sfConvexShape_getTransform(shape);

	
}

int main(int ac, char **av)
{
	sfRenderWindow *window;
	sfRectangleShape *moving_rect;
	sfRectangleShape *static_rect;
	sfVector2f moving_rect_size = {100.0, 100.0};
	sfVector2f static_rect_size = {100.0, 100.0};
	sfVector2f moving_rect_pos = {500.0, 500.0};
	sfVector2f static_rect_pos = {700.0, 300.0};
	sfVector2f movement = {5.0, 0};

  // Create the window
	window = my_window_create();

  // Create the rectangle entities
	moving_rect = create_rectangle_entity(moving_rect_size, sfBlue);
	static_rect = create_rectangle_entity(static_rect_size, sfRed);
	sfRectangleShape_setPosition(moving_rect, moving_rect_pos);
	sfRectangleShape_setPosition(static_rect, static_rect_pos);

  // Main Loop
	while (sfRenderWindow_isOpen(window)) {
		// Clear the screen
		sfRenderWindow_clear(window, sfBlack);
		// Move the moving rectangle
		sfRectangleShape_rotate(moving_rect, 1);
//		sfRectangleShape_move(moving_rect, movement);
		// Check collision between the two rectangles
		// and print a message they collide each other
		if (check_rectangle_collision(moving_rect, static_rect) == sfTrue)
	{
	  my_putstr("It collides\n");
	}
		// Draw and display
		sfRenderWindow_drawRectangleShape(window, moving_rect, NULL);
		sfRenderWindow_drawRectangleShape(window, static_rect, NULL);
		sfRenderWindow_display(window);
	}
	return (0);
}
