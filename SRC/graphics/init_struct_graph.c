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
		("include/data_base/", NULL);
	plane.sprite = sfSprite_create();
	plane.pos.x = list->dep_x * 10;
	plane.pos.y = list->dep_y * 10;
	return (plane);
}

s_tower_t init_sprite_tower(tower_t *list)
{
	s_tower_t tower;

	tower.texture = sfTexture_createFromFile
		("include/data_base/", NULL);
	tower.sprite = sfSprite_create();
	tower.pos.x = list->tow_x;
	tower.pos.y = list->tow_y;
	return (tower);
}
