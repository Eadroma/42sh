##
## EPITECH PROJECT, 2020
## B-PSU-210-PAR-2-2-42sh-victoire.rabeau
## File description:
## Makefile
##

CPPFLAGS	= -I./include

CFLAGS		= 	-Wall -Wextra

LDFLAGS = -lmy -L. -lncurses

SRC	=	main.c											\
		shell.c											\
		commands.c										\
		path_finding.c									\
		init/init_struct.c								\
		display/display_prompt.c						\
		parsing/semicolon_parsing.c						\
		parsing/parser.c								\
		parsing/clean_cmd_line.c						\
		parsing/delimitors.c							\
		builtins/echo/echo.c							\
		builtins/echo/check_flags.c						\
		builtins/cd.c									\
		builtins/env/env.c								\
		builtins/env/getenv.c							\
		builtins/env/setenv.c							\
		builtins/env/unsetenv.c							\
		builtins/exit.c									\
		builtins/alias/alias.c							\
		builtins/alias/init_alias.c						\
		builtins/alias/save_alias.c						\
		builtins/alias/alias_management.c				\
		builtins/history/history.c						\
		exec/my_exec.c									\
		exec/my_dup.c									\
		delimitors/redirections/standard_functions.c	\
		delimitors/redirections/simple_standard_input.c	\
		delimitors/redirections/double_standard_input.c	\
		delimitors/redirections/standard_output.c		\
		delimitors/and.c								\
		delimitors/or.c									\
		delimitors/semicolon.c							\
		delimitors/pipe/pipe.c							\
		args/args_management.c							\
		args/reset_list.c								\
		free/free_array.c


SSRC	=		$(addprefix src/, $(SRC))

OBJ		=	$(SSRC:.c=.o)

NAME		= 	42sh

MAKE		=	make

CC 		= 	gcc

all: $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "\e[92;5m       ====BULDING DONE====      \e[0m"

vg:	CFLAGS += -g3
vg:	fclean lib $(NAME)

clean:
	make clean -C ./lib
	rm -f $(OBJ) *.gcda *.gcno vg*

fclean:	clean
	make fclean -C ./lib
	rm -f $(NAME)

re:	fclean all

tests:
	@make re
	exec ./test/tests.sh

.PHONY: all clean fclean re lib vg
