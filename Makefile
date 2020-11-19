##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/open_folder.c	\
		src/sort_names.c	\
		src/read_info.c		\
		src/reverse_order.c	\
		src/print_special.c	\
		src/my_puterror.c	\
		src/parse_errors.c	\
		src/print_info.c	\
		src/my_intlen.c		\
		src/calc_max_sizes.c	\
		src/sort_time.c		\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include -g

LIB	=	-L ./lib/my -lmy

NAME	=	my_ls

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my re
