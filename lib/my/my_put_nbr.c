/*
** EPITECH PROJECT, 2017
** my_put_number
** File description:
** put number
*/

#include "my.h"

int my_put_nbr(int nb)
{
	int i = 1;
	int result;

	if (nb == 0)
		my_putchar ('0');
	if (nb < 0) {
		my_putchar ('-');
		nb = nb * (-1);
	}
	while (i <= nb) {
		i *= 10;
	}
	while (i > 1) {
		i = i / 10;
		result = (nb / i) % 10;
		my_putchar(result + 48);
	}
	return (0);
}
