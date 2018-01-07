/*
** EPITECH PROJECT, 2017
** ohhéé
** File description:
** hééé
*/

#ifndef MY_H
#define MY_H
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
}framebuffer_t;

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
char **my_str_to_word_array(char *);
int sum_stdarg(int i, int nb, ...);
void disp_c(va_list ap);
void disp_s(va_list ap);
void disp_i(va_list ap);
void disp_mod(va_list ap);
int my_putnbr_base(unsigned int nb, char *base);
void disp_o(va_list ap);
void disp_x(va_list ap);
void disp_x_m(va_list ap);
void disp_u(va_list ap);
void disp_b(va_list ap);
void disp_s_m(va_list ap);
void disp_p(va_list ap);
int my_put_unsigned(unsigned int nb);
int octal_base(unsigned int nb);
int zero_case(char *s, int i);
void display_s(char s);
int display_l(char *s, int i);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
framebuffer_t *fb_clean(framebuffer_t *fb, unsigned width, unsigned height);
int my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y,
		  sfColor color);
void draw_square(framebuffer_t *framebuffer, sfVector2i pos,
		 sfVector2i size, sfColor color);
int draw_line(framebuffer_t *framebuffer, sfVector2i point_a,
	      sfVector2i point_b, sfColor color);
int draw_triangle(framebuffer_t *fb, sfVector2i pa, sfVector2i pb,
		  sfVector2i pc);
int draw_cube(framebuffer_t *fb, int r, sfColor color);
int draw_circle(framebuffer_t *buffer, sfVector2i center, int r, sfColor color);
int draw_border(framebuffer_t *buffer, sfVector2i center, int r ,sfColor color);
void refresh(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture,
	     framebuffer_t *framebuffer);

#endif /* MY_H_ */
