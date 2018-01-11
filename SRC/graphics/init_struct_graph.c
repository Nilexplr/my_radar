/*
** EPITECH PROJECT, 2018
** init_struct_graph.c
** File description:
** init graphics structure functions
*/

#include "my_radar.h"

background_t *init_back(void)
{
	background_t *back = malloc(sizeof(background_t));

	back->texture =
		sfTexture_createFromFile
		("include/data_base/background.png", NULL);
	back->sprite = sfSprite_create();
}
