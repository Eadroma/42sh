##
## EPITECH PROJECT, 2020
## PSU_my_ls_2019
## File description:
## Makefile
##

SRC =	my_str_to_word_array.c	\
		my_strcmp.c				\
		my_strchr.c				\
		my_strcat.c				\
		my_realloc_array.c		\
		my_strincl.c			\
		remove_line_array.c		\
		remove_char.c			\
		cut_str.c				\
		remove_first_word.c		\
		end_str.c

CPPFLAGS = -I../include

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

vg:	CFLAGS += -g3
vg:	$(NAME)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: 	fclean all

.PHONY: all clean fclean re
