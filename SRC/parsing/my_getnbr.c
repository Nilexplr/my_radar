/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** get nbr
*/

int display_number(char const *str, int i, int number)
{
	int b = 0;
	int c = 0;

	if (str[i] >= '0' && str[i] <= '9') {
		b = str[i] - 48;
		number += b;
		i++;
		c++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		number *= 10;
	if (c > 11)
		number = 0;
	return (number);
}

int watch_folow(char const *str, int i, int j)
{
	if (str[i] > '9' || str[i] < '0') {
		j++;
	}
	return (j);
}

int my_getnbr(char const *str)
{
	int a = 0;
	int i= 0;
	int result = 0;
	int j = 0;

	while (str[i] != '\n' && j == 0 && str[i] != '\0') {
		if (str[i] == '-' && str[i + 1] <= '9' && str[i + 1] >= '0')
			a = -1;
		result = display_number(str, i, result);
		if ('0' <= str[i] && str[i] >= '9')
			j = watch_folow(str, i, j);
		i++;
	}
	if (a == -1)
		result *= (-1);
	return (result);
}
