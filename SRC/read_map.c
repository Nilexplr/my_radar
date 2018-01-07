/*
** EPITECH PROJECT, 2017
** read_map.c
** File description:
** read map functions
*/

#include "my.h"

char *read_map(char *s)
{
	char *buff = malloc(sizeof(char) * 30720);
	int size = 0;
	int fd = open(s, O_RDONLY);

	if (fd == -1)
		exit(84);
	size = read(fd, buff, 30719);
	buff[size] = '\0';
	return (buff);
}

int count_line(char *s)
{
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] == '\n')
			count++;
	return (count);
}

char **define_map(int ac, char **av)
{
	char *s = read_map(av[1]);
	int line = count_line(s);
	char **map = my_str_to_line_array(s, line + 1);

	return (map);
}
