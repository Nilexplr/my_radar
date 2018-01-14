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
	if (ac != 2) {
		write(2 , "./my_radar:\tbad arguments:\t", 27);
		my_put_nbr(ac - 1);
		write(2, " given but 1 is required\n", 25);
		write(2, "retry with -h\n", 14);
		return (84);
	}
	if (print_usage(av[1]) == 1)
		return (0);
	if (detect_error(av[1]) == 1) {
		write(2, "Error in the file, please check the values.\n", 44);
		return (84);
	}
	game_loop(ac, av);
	return (0);
}
