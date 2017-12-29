/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** find the square of a number
*/

#include "my.h"

int my_compute_square_root (int nb)
{
	int i = 1;
	int n = 1;

	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	while (n < nb) {
		i++;
		n = i*i;
		if (n > nb)
			return (0);
		if (n == nb)
			return (i);
	}
	return (0);
}
