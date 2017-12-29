/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
	int memoire_a;

	memoire_a = *a;
	*a = *b;
	*b = memoire_a;
}
