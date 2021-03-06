/*
** EPITECH PROJECT, 2018
** my_radar.h
** File description:
** .h for my radar
*/

#ifndef MY_RADAR_H
#define MY_RADAR_H
#include "struct.h"
#include "my.h"

char **define_map(char *av);
item_t *init_item(void);
void add_plane(plane_t *plane, char *s);
void add_tower(tower_t *tower, char *s);
void add_area(area_t *area, char *s);
void game_loop(int ac, char **av);
int print_usage(char *str);
char **my_str_to_line_array(char *str, int number_line);
void open_window(item_t *all);
background_t init_back(void);
s_plane_t init_sprite_plane(plane_t *list);
s_tower_t init_sprite_tower(tower_t *list);
s_area_t init_sprite_area(area_t *list);
void prepare(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture);
void destroy(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture);
sfRectangleShape *create_rectangle_entity(s_plane_t plane);
sfCircleShape *create_circle_entity(s_tower_t tower, float radius);
sfConvexShape *create_convex_entity(s_area_t area);
void draw_all(item_t *all, sfRenderWindow *window);
void prepare_all(item_t *all);
void mouvement_all(item_t *all);
sfVector2f init_mouvement(sfVector2f point_a, sfVector2f point_b);
float init_rotate(sfVector2f dep, sfVector2f arr);
int detect_collision(transformed_shape_t *obj1, transformed_shape_t *obj2);
void setup_collision(int option, ...);
int define_end(item_t *all);
void destroy_plane(plane_t *plane);
int detect_error(char *av);
item_t *prepare_game(char *av);
void collision_all(item_t *all);
transformed_shape_t *convex_transformed_shape(sfConvexShape *shape);
transformed_shape_t *rectangle_transformed_shape(sfRectangleShape *shape);
int number_word(char *str);

#endif /* MY_RADAR_H */
