/*
** EPITECH PROJECT, 2018
** setup_collision.c
** File description:
** setup collision functions
*/

#include "my_radar.h"

void collision_convex_plane(va_list ap)
{
	area_t *area = va_arg(ap, area_t*);
	plane_t *plane = va_arg(ap, plane_t*);
	transformed_shape_t *obj1 = area->sprite.transfo;
	transformed_shape_t *obj2 = plane->sprite.transfo;

	obj1 = convex_transformed_shape(area->sprite.convex);
	obj2 = rectangle_transformed_shape(plane->sprite.rect);

	if (detect_collision(obj1, obj2) == 1) {
		destroy_plane(plane);
		my_putstr("It collides\n");
	}
}

void collision_plane_plane(va_list ap)
{
	plane_t *plane1 = va_arg(ap, plane_t*);
	plane_t *plane2 = va_arg(ap, plane_t*);
	transformed_shape_t *obj1 = plane1->sprite.transfo;
	transformed_shape_t *obj2 = plane2->sprite.transfo;

	obj1 = rectangle_transformed_shape(plane1->sprite.rect);
	obj2 = rectangle_transformed_shape(plane2->sprite.rect);

	if (detect_collision(obj1, obj2) == 1) {
		destroy_plane(plane1);
		destroy_plane(plane2);
		my_putstr("It collides\n");
	}
	free(obj1);
	free(obj2);
}

void setup_collision(int option, ...)
{
	va_list ap;

	va_start(ap, option);
	if (option == 1)
		collision_convex_plane(ap);
	if (option == 2)
		collision_plane_plane(ap);
	va_end(ap);
}

void collision_all(item_t *all)
{
	if (all->plane->next->next == all->plane->prec && all->plane->next->next != all->plane) {
		setup_collision(2, all->plane->next, all->plane->prec);
	}
	for (plane_t *it = all->plane->next; it->next->next != all->plane; it = it->next) {
		for (plane_t *itb = it->next; itb != all->plane; itb = itb->next) {
			setup_collision(2, it, itb);
		}
	}
	for (area_t *it = all->area->next; it != NULL; it = it->next) {
		for (plane_t *itb = all->plane->next; itb != all->plane; itb = itb->next) {
			setup_collision(1, it, itb);
		}
	}
}
