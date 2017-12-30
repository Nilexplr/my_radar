/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main my_radar
*/

int main(int ac, char **av)
{
	int i = 0;

	if (ac != 2)
		return (84);
	if (print_usage(av[1]) == 1)
		return (0);
}
