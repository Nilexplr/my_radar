##
## EPITECH PROJECT, 2017
## My_popup_2017
## File description:
## Makefile
##

SRC	=	./SRC/main.c				\
		./SRC/graphics/setup_mouvement.c	\
		./SRC/graphics/open_window.c		\
		./SRC/graphics/setup_window.c		\
		./SRC/graphics/init_struct_graph.c	\
		./SRC/graphics/setup_shape.c		\
		./SRC/graphics/game_loop.c		\
		./SRC/parsing/display_loop.c		\
		./SRC/parsing/my_getnbr.c		\
		./SRC/parsing/my_str_to_word_array.c	\
		./SRC/parsing/my_str_to_line_array.c	\
		./SRC/parsing/init_struct.c		\
		./SRC/parsing/read_map.c		\
		./SRC/usage.c				\
		./SRC/parsing/struct_function.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -W -Wall -Wextra -pedantic -g3

NAME	=	my_radar

LIB_DIR	=	./lib/my

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) -L$(LIB_DIR) -lmy -lm -lc_graph_prog $(CFLAGS)
		rm $(OBJ)

clean:
	rm -f $(OBJ) $(LIB_OBJ) *.gc*

fclean:	clean
	rm -f $(NAME) $(UT)

re:	fclean all
