/*
** EPITECH PROJECT, 2018
** detect_collision.c
** File description:
** detect collision functions
*/

#include "my_radar.h"

sfVector2f project_point_on_axis(float axis_slopes, sfVector2f to_project)
{
	sfVector2f projected_point;
	float m = axis_slopes;

	projected_point.x = (m * to_project.y + to_project.x) / (m * m + 1);
	projected_point.y =
		(m * m * to_project.y + m * to_project.x) / (m * m + 1);
	return (projected_point);
}

int detect_min(sfVector2f *obj, int nb)
{
	sfVector2f min = obj[0];
	int value = 0;

	for (int i = 0; i < nb; i++)
		if (obj[i].x < min.x) {
			min = obj[i];
			value = i;
		}
	return (value);
}

int detect_max(sfVector2f *obj, int nb)
{
	sfVector2f max = obj[0];
	int value = 0;

	for (int i = 0; i < nb; i++)
		if (obj[i].x > max.x) {
			max = obj[i];
			value = i;
		}
	return (value);
}

int detect_overlap(sfVector2f *obj1, sfVector2f *obj2, int nb1, int nb2)
{
	int i_max = detect_max(obj1, nb1);
	int i_min = detect_min(obj1, nb1);
	int j_max = detect_max(obj2, nb2);
	int j_min = detect_min(obj2, nb2);

	if (obj1[i_min].x <= obj2[j_max].x && obj1[i_min].x >= obj2[j_min].x)
		return (1);
	if (obj1[i_max].x >= obj2[j_min].x && obj1[i_max].x <= obj2[j_max].x)
		return (1);
	if (obj2[j_min].x <= obj1[i_max].x && obj2[j_min].x >= obj1[i_min].x)
		return (1);
	if (obj2[j_max].x >= obj1[i_min].x && obj2[j_max].x <= obj1[i_max].x)
		return (1);
	return (0);
}

int detect_collision(transformed_shape_t *obj1, transformed_shape_t *obj2)
{
	sfVector2f *projected1 = malloc(sizeof(sfVector2f) * obj1->point_count);
	sfVector2f *projected2 = malloc(sizeof(sfVector2f) * obj2->point_count);

	for (int j = 0; j < obj1->point_count; j++) {
		for (int i = 0; i < obj1->point_count; i++)
			projected1[i] = project_point_on_axis(obj1->axis_slopes[j], obj1->points[i]);
		for (int i = 0; i < obj2->point_count; i++)
			projected2[i] = project_point_on_axis(obj1->axis_slopes[j], obj2->points[i]);
		if (detect_overlap(projected1, projected2, obj1->point_count, obj2->point_count) == 0)
			return (0);
	}
	for (int j = 0; j < obj2->point_count; j++) {
		for (int i = 0; i < obj1->point_count; i++)
			projected1[i] = project_point_on_axis(obj2->axis_slopes[j], obj1->points[i]);
		for (int i = 0; i < obj2->point_count; i++)
			projected2[i] = project_point_on_axis(obj2->axis_slopes[j], obj2->points[i]);
		if (detect_overlap(projected1, projected2, obj1->point_count, obj2->point_count) == 0)
			return (0);
	}
	return (1);
}
