/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main my_radar
*/

#include "my.h"
#include "my_radar.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return (84);
	if (print_usage(av[1]) == 1)
		return (0);
	game_loop(ac, av);
}
