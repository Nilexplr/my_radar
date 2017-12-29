/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** prime_sup
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

int my_find_prime_sup(int nb)
{
	int result;

	result = my_is_prime(nb);
	if (result == 0)
		my_find_prime_sup(nb + 1);
	else
		return(nb);
	return (0);
}

