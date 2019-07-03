##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make files
##

NAME	=	matchstick

CFLAGS  =       -W  -Wextra -Wall

SRC	=	src/ai.c		\
		src/map.c		\
		src/create_map.c	\
		src/my_atoi.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./my_printf/ -lmy

CPPFLAGS	+=	-Iinclude/

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C my_printf/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)	\
	rm -f *~	\
	rm -f *#	\

re:	fclean clean all

.PHONY:	all re clean fclean
