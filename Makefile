##
## EPITECH PROJECT, 2020
## B-CPE-100-RUN-1-1-cpoolday11-mathieu.muty
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/load_file_in_mem.c	\
		src/my_str_to_word_array.c \
		src/game_of_life.c 	\
		src/analyse.c		\
		src/check_char.c

SRC_TEST=	src/load_file_in_mem.c \
		src/my_str_to_word_array.c \

NAME	=	gameoflife

NAME_TEST=	unit_test

IFLAG	=	-I ../include/

LFLAG	=	-L lib/my -lmy

WFLAG	=	-W -Wall -Wextra -Werror

CRIFLAG	=	-l criterion --coverage

GDBFLAG	=	-g -g3

all:
	make -C lib/my all
	gcc  $(SRC) -o $(NAME) $(IFLAG) $(LFLAG) $(WFLAG) $(GDBFLAG)

test_run:
	make -C lib/my all
	gcc $(SRC_TEST) -o $(NAME_TEST) $(IFLAG) $(LFLAG) $(WFLAG) $(CRIFLAG)
	./unit_test

clean:
	make -C lib/my clean
	rm -f *~
	rm -f *#
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	make -C lib/my fclean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

re: fclean all
