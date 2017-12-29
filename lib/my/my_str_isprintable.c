/*
** EPITECH PROJECT, 2017
** my_str_isprintable
** File description:
** isprintable
*/

int my_str_isprintable(char const *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++) {
		if (str [i] < 32)
			return (0);
	}
	return (1);
}
