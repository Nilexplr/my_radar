##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

SRC	=	draw_line.c		\
		draw_square.c		\
		framebuffer_create.c	\
		my_put_pixel.c		\
		clear_framebuffer.c	\
		draw_triangle.c	\
		draw_circle.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_revstr.c		\
		disp_stdarg.c		\
		my_putnbr_base.c	\
		disp_basearg.c		\
		my_putunsignedint.c	\
		disp_ptrarg.c		\
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	build

build:
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp sflm.h ../../include/
	cp my.h ../../include/
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
