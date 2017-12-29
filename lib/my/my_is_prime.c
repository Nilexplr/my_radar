/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** prime number or not
*/

int my_is_prime( int nb)
{
	int i = 2;

	while (nb % i != 0){
		i++;
		if (i == nb/2)
			return (1);
		if (nb % i == 0)
			return (0);
	}
	return (0);
}
