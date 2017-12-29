/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** n characters string to line
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i;
	int j = 0;

	while (dest[j] != '\0')
		j++;
	for (i = 0; i < n; i++) {
		dest[i] = src[i];
		if (i > j)
			dest[n + 1] = '\0';
	}
	return(dest);
}
