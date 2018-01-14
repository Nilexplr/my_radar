/*
** EPITECH PROJECT, 2018
** setup_transformed_shape.c
** File description:
** setup transformed shape functions
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
