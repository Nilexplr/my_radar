/*
** EPITECH PROJECT, 2018
** init_struct_graph.c
** File description:
** init graphics structure functions
*/

#include "my_radar.h"

background_t init_back(void)
{
	background_t back;

	back.texture =
		sfTexture_createFromFile
		("include/data_base/background.png", NULL);
	back.sprite = sfSprite_create();
	return (back);
}

s_plane_t init_sprite_plane(plane_t *list)
{
	s_plane_t plane;

	plane.texture = sfTexture_createFromFile
		("include/data_base/gardian.png", NULL);
	plane.pos.x = list->dep_x * 10;
	plane.pos.y = list->dep_y * 10;
	plane.rect = create_rectangle_entity(plane);
	return (plane);
}

s_tower_t init_sprite_tower(tower_t *list)
{
	s_tower_t tower;

	tower.texture = sfTexture_createFromFile
		("include/data_base/planet.png", NULL);
	tower.pos.x = list->tow_x * 10;
	tower.pos.y = list->tow_y * 10;
	tower.circle = create_circle_entity(tower, list->radius);
	return (tower);
}

s_area_t init_sprite_area(area_t *list)
{
	s_area_t area;
	int j = 0;

	area.texture = sfTexture_createFromFile
		("include/data_base/asteroid-sprite.png", NULL);
	area.point_count = list->nb_coord;
	area.points = malloc(sizeof(sfVector2f) * area.point_count);
	for (int i = 0; i < area.point_count; i++) {
		area.points[i].x = list->coord[j] * 10;
		area.points[i].y = list->coord[j + 1] * 10;
		j += 2;
	}
	area.convex = create_convex_entity(area);
	return (area);
}
