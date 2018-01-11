##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## julien.ollivier@epitech.eu
##

SRC	=	./SRC/usage.c				\
		./SRC/graphics/open_windows.c		\
		./SRC/graphics/setup_windwo.c		\
		./SRC/graphics/init_struct_graph.c	\
		./SRC/graphics/display_loop.c		\
»       »       ./SRC/parsing/my_getnbr.c		\
»       »       ./SRC/parsing/my_str_to_word_array.c	\
»       »       ./SRC/parsing/my_str_to_line_array.c	\
»       »       ./SRC/parsing/init_struct.c		\
»       »       ./SRC/parsing/read_map.c			\
»       »       ./SRC/parsing/struct_function.c

TEST	=	

MAIN	=	./SRC/main.c  \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

CC	=	gcc -c $(HEADER) $(GRAPH) $(CDFLAG)

LIB	=	-L./lib/ -lmy

CRITERION	=	-lcriterion --coverage

GRAPH	=	-lc_graph_prog

HEADER	=	-I./include/

CDFLAG	=	-W -Wall -Wextra -pedantic

all:	$(NAME)

$(NAME):	$(OBJ) $(MAIN:.c=.o)
	make -C./lib/my
	$(CC) -o $(NAME) $(MAIN:.c=.o) $(OBJ) $(LIB)

tests_run:
	./unit_test/script/
	make -C./lib/my
	$(CC) -o test $(HEADER) $(SRC) $(TEST) $(LIB) $(GRAPH) $(CRITERION)
	./test
	rm -f ./test

gdb:
	make -C./lib/my/
	$(CC) $(MAIN) $(HEADER) $(SRC) $(LIB) $(GRAPH) -g3
	gdb ./a.out

valgrind:
	make -C./lib/my
	$(CC) $(HEADER) $(MAIN) $(SRC) $(LIB) $(GRAPH) -g3
	valgrind --leak-check=full ./a.out map

grep:
	grep   $(SRC)

wc:
	wc $(SRC) ./include/*.h $(TEST)

clean:
	make clean -C./lib/my
	rm -f $(OBJ) $(MAIN:.c=.o) *.gc* map map1 map2 map3
	mr_clean

fclean: clean
	make fclean -C./lib/my
	rm -f $(NAME) a.out test
	clear
	tree

re:	fclean all

