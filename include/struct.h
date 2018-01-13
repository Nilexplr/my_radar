/*
** EPITECH PROJECT, 2017
** struct.h
** File description:
** structures for my_radar
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include "my.h"

typedef struct transformed_s
{
	int point_count;
	sfVector2f *points;
	float *axis_slopes;
}transformed_shape_t;

typedef struct sprite_background_s {
	sfTexture *texture;
	sfSprite *sprite;
}background_t;

typedef struct sprite_plane_s {
	sfTexture *texture;
	sfVector2f pos;
	sfVector2f end;
	sfVector2f mouvement;
	sfRectangleShape *rect;
	transformed_shape_t *transfo;
}s_plane_t;

typedef struct sprite_tower_s {
	sfTexture *texture;
	sfVector2f pos;
	sfCircleShape *circle;
}s_tower_t;

typedef struct sprite_area_s {
	sfTexture *texture;
	int point_count;
	sfVector2f *points;
	sfConvexShape *convex;
	transformed_shape_t *transfo;
}s_area_t;

typedef struct plane_s {
	int dep_x;
	int dep_y;
	int arr_x;
	int arr_y;
	int speed;
	int delay;
	int display;
	s_plane_t sprite;
	struct plane_s *next;
	struct plane_s *prec;
}plane_t;

typedef struct tower_s {
	int tow_x;
	int tow_y;
	int radius;
	int display;
	s_tower_t sprite;
	struct tower_s *next;
}tower_t;

typedef struct area_s {
	int *coord;
	int nb_coord;
	int display;
	s_area_t sprite;
	struct area_s *next;
}area_t;

typedef struct item_s {
	plane_t *plane;
	tower_t *tower;
	area_t *area;
}item_t;

#endif /* STRUCT_H_ */
