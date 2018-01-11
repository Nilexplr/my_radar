/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** structures for my_radar
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include "my.h"

typedef struct sprite_background_s {
	sfTexture *texture;
	sfSprite *sprite;
}background_t;

typedef struct sprite_plane_s {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
}s_plane_t;

typedef struct sprite_tower_s {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
}s_tower_t;

typedef struct sprite_area_s {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
}s_area_t;

typedef struct plane_s {
	int dep_x;
	int dep_y;
	int arr_x;
	int arr_y;
	int speed;
	int delay;
	int display;
	struct plane_s *next;
}plane_t;

typedef struct tower_s {
	int tow_x;
	int tow_y;
	int radius;
	int display;
	struct tower_s *next;
}tower_t;

typedef struct area_s {
	int *coord;
	int display;
	struct area_s *next;
}area_t;

typedef struct item_s {
	plane_t *plane;
	tower_t *tower;
	area_t *area;
}item_t;

#endif /* STRUCT_H_ */
