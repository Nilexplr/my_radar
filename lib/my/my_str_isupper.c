/*
** EPITECH PROJECT, 2017
** my_str_isupper
** File description:
** isupper
*/

int my_str_isupper(char const *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
	}
	return (1);
}
