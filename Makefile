##
## EPITECH PROJECT, 2017
## My_radar_2017
## File description:
## Makefile
##

LIB_DIR	=	./lib/my/

LIB_SRC	=	$(LIB_DIR)	\

LIB_OBJ	=	$(LIB_DIR)*.o

LIB	=	libmy.a

UT_DIR	=	./tests/

UT_SRC	=	$(UT_DIR)	\


UT	=	units

LDFLAGS	=	-lcriterion -lgcov -coverage

SRC	=	main.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -W -Wall -Wextra -pedantic -g3

NAME	=	my_radar

all:		$(NAME)

$(NAME):	$(OBJ)
	make re -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) -L$(LIB_DIR) -lmy -lc_graph_prog

tests_run:
	gcc -o $(UT) $(UT_SRC) $(LIB_SRC) $(CFLAGS) $(LDFLAGS)
	./$(UT)

clean:
	rm -f $(OBJ) $(LIB_OBJ) *.gc*

fclean:	clean
	rm -f $(NAME) $(UT) $(LIB_DIR)$(LIB)

re:	fclean all
