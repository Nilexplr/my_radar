/*
** EPITECH PROJECT, 2018
** setup_shape.c
** File description:
** setup shape functions
*/

#include "my_radar.h"

sfRectangleShape *create_rectangle_entity(s_plane_t plane)
{
	sfRectangleShape *rec = sfRectangleShape_create();
	sfVector2f size = {40, 40};
	sfVector2f origin = {20, 20};

	sfRectangleShape_setSize(rec, size);
	sfRectangleShape_setOutlineThickness(rec, 2);
	sfRectangleShape_setOutlineColor(rec, sfCyan);
	sfRectangleShape_setTexture(rec, plane.texture, sfTrue);
	sfRectangleShape_setOrigin(rec, origin);
	sfRectangleShape_setRotation(rec, init_rotate(plane.pos, plane.end));
	sfRectangleShape_setPosition(rec, plane.pos);
	return (rec);
}

sfCircleShape *create_circle_entity(s_tower_t tower, float radius)
{
	sfCircleShape *shape = sfCircleShape_create();
	sfVector2f origin = {radius * 10, 10 * radius};

	sfCircleShape_setRadius(shape, 10 * radius);
	sfCircleShape_setOutlineThickness(shape, 2);
	sfCircleShape_setOutlineColor(shape, sfGreen);
	sfCircleShape_setTexture(shape, tower.texture, sfTrue);
	sfCircleShape_setOrigin(shape, origin);
	sfCircleShape_setPosition(shape, tower.pos);
	return (shape);
}

sfConvexShape *create_convex_entity(s_area_t area)
{
	sfConvexShape *shape = sfConvexShape_create();

	sfConvexShape_setPointCount(shape, area.point_count);
	for (int i =0; i < area.point_count; i++)
		sfConvexShape_setPoint(shape, i, area.points[i]);
	sfConvexShape_setOutlineThickness(shape, 2);
	sfConvexShape_setOutlineColor(shape, sfYellow);
	sfConvexShape_setTexture(shape, area.texture, sfTrue);
	return (shape);
}
