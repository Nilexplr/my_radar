/*
** EPITECH PROJECT, 2017
** usage.c
** File description:
** print usage function
*/

#include "my.h"

void disp_h(void)
{
	my_printf("Space traffic simulation panel.\n\n");
	my_printf("USAGE\n ./my_radar [OPTIONS] path_to_script\n");
	my_printf(" path_to_script\tThe path to the script file.\n");
	my_printf("\nOPTIONS\n -h\t\tprint the usage and quit\n\n");
	my_printf("USER INTERACTIONS\n 'L' key\tenable/disable");
	my_printf(" hitboxes, areas and limits.\n 'S' key\t");
	my_printf("enable/disable sprites.\n");
}

int print_usage(char *str)
{
	if (str[0] == '-')
		if (str[1] == 'h'){
			disp_h();
			return (1);
		}
	return (0);
}
