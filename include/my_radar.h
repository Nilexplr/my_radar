/*
** EPITECH PROJECT, 2018
** my_radar.h
** File description:
** .h for my radar
*/

#ifndef MY_RADAR_H
#define MY_RADAR_H
#include "struct.h"

char **define_map(int ac, char **av);
item_t *init_item(void);
void add_plane(plane_t *plane, char *s);
void add_tower(tower_t *tower, char *s);
void add_area(area_t *area, char *s);
void game_loop(int ac, char **av);
int print_usage(char *str);
char **my_str_to_line_array(char *str, int number_line);

#endif /* MY_H_ */
