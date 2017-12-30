/*
** EPITECH PROJECT, 2017
** sflm.h
** File description:
** function sfml
*/

#ifndef MY_H
#define MY_H
#include <SFML/Window/Event.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;

typedef struct coordinate_s{
	sfVector2i pa;
	sfVector2i pb;
	sfVector2i pc;
	sfVector2i pd;
	sfVector2i pe;
	sfVector2i pf;
	sfVector2i pg;
	sfVector2i ph;
}coord_t;

typedef struct screen_savior_s{
	sfVideoMode mode;
	sfTexture *texture;
	sfSprite *sprite;
	sfRenderWindow *window;
	framebuffer_t *fb;
	sfEvent event;
}screns_t;


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
void draw_dragon(framebuffer_t *fb, double a, double j);
void loop_fractal(sfRenderWindow *window, sfSprite *sprite,
		  sfTexture *texture, framebuffer_t *framebuffer);
void draw_helice(framebuffer_t *fb, double a, double j);
void ftriangle(framebuffer_t *fb, double a, double j);
void draw_tree(framebuffer_t *fb, double a, double j);
void draw_fsquare(framebuffer_t *fb, double a, double j);
void close_window(sfRenderWindow *window, sfEvent event);
void prepare(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture);
void destroy(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture);
void refresh(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture,
	     framebuffer_t *framebuffer);
void disp_c(va_list ap);
void disp_s(va_list ap);
void disp_i(va_list ap);
void disp_mod(va_list ap);
int my_putnbr_base(unsigned int nb, char *base);
void disp_o(va_list ap);
void disp_x(va_list ap);
void disp_X(va_list ap);
void disp_u(va_list ap);
void disp_b(va_list ap);
void disp_S(va_list ap);
void disp_p(va_list ap);
int my_put_unsigned(unsigned int nb);
int octal_base(unsigned int nb);
int zero_case(char *s, int i);
void display_s(char s);
int display_l(char *s, int i);
int my_printf(char *s, ...);
void play_triangle(void);
void play_cube(void);
void game_cube(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture,
	       framebuffer_t *framebuffer);
void game_triangle(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture,
		   framebuffer_t *framebuffer);

#endif /* MY_H_ */
