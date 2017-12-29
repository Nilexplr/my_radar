/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** nicolas.garde@epitech.eu
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>

#define VAL(x) (x - '0')
#define ASCII(x) (x + '0')

int my_compute_power_rec(int nb, int p);
int my_compute_square_root (int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime( int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *fix_number(char *str);
char *addition(char *str1, char *str2);
int define_negativstr(char *str1, char *str2);
char **my_str_to_word_array(char *str, int);

#endif /* MY_H_ */
