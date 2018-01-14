/*
** EPITECH PROJECT, 2018
** setup_collision.c
** File description:
** setup collision functions
*/

#include "my_radar.h"

float calcul_axis_slopes(sfVector2f a, sfVector2f b)
{
	float axis_slopes;

	if (a.y - b.y == 0) {
		axis_slopes = 0;
		return(axis_slopes);
	}
	axis_slopes = -(a.x - b.x)/(a.y - b.y);
	return (axis_slopes);
}

transformed_shape_t *convex_transformed_shape(sfConvexShape *shape)
{
	transformed_shape_t *ts =
		malloc(sizeof(transformed_shape_t));
	sfTransform transform = sfConvexShape_getTransform(shape);
	int b;

	ts->point_count = sfConvexShape_getPointCount(shape);
	ts->axis_slopes = malloc(sizeof(float) * ts->point_count);
	ts->points = malloc(sizeof(sfVector2f) * ts->point_count);
	for (int i = 0; i < ts->point_count; i++)
		ts->points[i] =
			sfTransform_transformPoint
			(&transform, sfConvexShape_getPoint(shape, i));
	for (int i = 0; i < ts->point_count; i++) {
		b = i + 1;
		if (b == ts->point_count)
			b = 0;
		ts->axis_slopes[i] = calcul_axis_slopes
			(ts->points[i], ts->points[b]);
	}
	return (ts);
}

transformed_shape_t *rectangle_transformed_shape(sfRectangleShape *shape)
{
	transformed_shape_t *tshape =
		malloc(sizeof(transformed_shape_t));
	sfTransform transform = sfRectangleShape_getTransform(shape);
	int b;

	tshape->point_count = 4;
	tshape->points = malloc(sizeof(sfVector2f) * tshape->point_count);
	tshape->axis_slopes = malloc(sizeof(float) * 4);
	for (int i = 0; i < tshape->point_count; i++)
		tshape->points[i] =
			sfTransform_transformPoint
			(&transform, sfRectangleShape_getPoint(shape, i));
	for (int i = 0; i < tshape->point_count; i++) {
		b = i + 1;
		if (b == tshape->point_count)
			b = 0;
		tshape->axis_slopes[i] = calcul_axis_slopes
			(tshape->points[i],tshape->points[b]);
	}
	return (tshape);
}

void setup_collision(int option, ...)
{
	transformed_shape_t *obj1 = malloc(sizeof(transformed_shape_t));
	transformed_shape_t *obj2 = malloc(sizeof(transformed_shape_t));
	area_t *area = malloc(sizeof(area_t));
	plane_t *plane = malloc(sizeof(plane_t));
	va_list ap;

	va_start(ap, option);
	if (option == 1) {
		obj1 = convex_transformed_shape(va_arg(ap, area_t*)->sprite.convex);
		obj2 = rectangle_transformed_shape(va_arg(ap, plane_t*)->sprite.rect);
	}
	if (option == 2) {
		plane = va_arg(ap, plane_t*);
		obj1 = rectangle_transformed_shape(plane->sprite.rect);
		plane = va_arg(ap, plane_t*);
		obj2 = rectangle_transformed_shape(plane->sprite.rect);
	}
	if (detect_collision(obj1, obj2) == 1)
		my_putstr("It collides\n");
	va_end(ap);
}

void collision_all(item_t *all)
{
	if (all->plane->next->next->next == all->plane) {
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
