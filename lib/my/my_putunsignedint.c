/*
** EPITECH PROJECT, 2017
** put unsigned
** File description:
** put a unsigned int
*/

#include "my.h"

int my_put_unsigned(unsigned int nb)
{
	long int i = 1;
	long int result;

	if (nb == 0)
		my_putchar('0');
	if (nb < 0) {
		result = 4294967295 - nb;
		nb = result;
		result = 0;
	}
	while (i <= nb)
		i *= 10;
	while (i > 1) {
		i = i/10;
		result = (nb /i) % 10;
		my_putchar(result + 48);
		}
	return (0);
}
