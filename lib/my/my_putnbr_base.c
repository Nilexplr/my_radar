/*
** EPITECH PROJECT, 2017
** put nbr basd
** File description:
** change base
*/

#include "my.h"

int my_putnbr_base(unsigned int  nb, char *base)
{
	char *result = malloc(sizeof(char) * 11);
	int i = 0;
	char tmp;

	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	while (nb > 0) {
		tmp = nb % my_strlen(base);
		result[i] = base[tmp];
		nb = nb / my_strlen(base);
		i++;
	}
	my_revstr(result);
	my_putstr(result);
	return (0);
}

int octal_base(unsigned int nb)
{
	int result;
	int zero;
	int i = 1;

	if (nb < 64)
		my_putchar('0');
	if (nb < 8)
		my_putchar('0');
	while (i <= nb)
		i *= 10;
	while (i > 1) {
		i = i/8;
		result = (nb / i) % 8;
	       	my_putchar(result + 48);
	}
	return (0);
}
