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
	transformed_shape_t *transform_shape;
	sfTransform transform = sfConvexShape_getTransform(shape);
	int b;

	transform_shape->point_count = sfConvexShape_getPointCount(shape);
	transform_shape->axis_slopes = malloc(sizeof(float) * transform_shape->point_count);
	for (int i = 0; i < transform_shape->point_count; i++)
		transform_shape->points[i] =
			sfTransform_transformPoint
			(&transform, sfConvexShape_getPoint(shape, i));
	for (int i = 0; i < transform_shape->point_count; i++) {
		b = i + 1;
		if (b == transform_shape->point_count)
			b = 0;
		transform_shape->axis_slopes[i] = calcul_axis_slopes(transform_shape->points[i],
					   transform_shape->points[b]);
	}
	return (transform_shape);
}

transformed_shape_t *rectangle_transformed_shape(sfRectangleShape *shape)
{
	transformed_shape_t *transform_shape =
		malloc(sizeof(transformed_shape_t));
	sfTransform transform = sfRectangleShape_getTransform(shape);
	int b;

	transform_shape->point_count = 4;
	transform_shape->points = malloc(sizeof(sfVector2f) * transform_shape->point_count);
	transform_shape->axis_slopes = malloc(sizeof(float) * 4);
	for (int i = 0; i < transform_shape->point_count; i++)
		transform_shape->points[i] =
			sfTransform_transformPoint
			(&transform, sfRectangleShape_getPoint(shape, i));
	for (int i = 0; i < transform_shape->point_count; i++) {
		b = i + 1;
		if (b == transform_shape->point_count)
			b = 0;
		transform_shape->axis_slopes[i] =
			calcul_axis_slopes(transform_shape->points[i],
					   transform_shape->points[b]);
	}
	return (transform_shape);
}

void setup_collision(sfRectangleShape *obj1, sfRectangleShape *obj2)
{
	transformed_shape_t *transfobj1 = rectangle_transformed_shape(obj1);
	transformed_shape_t *transfobj2 = rectangle_transformed_shape(obj2);
	static int i = 0;

	if (detect_collision(transfobj1, transfobj2) == 1) {
		my_putstr("It collides\n");
		my_put_nbr(i);
		i++;
	}
}
