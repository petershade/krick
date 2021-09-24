NAME	= push_swap

SRC		= src/main.c \

OBJ		= $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			cc $(OBJ) $(CFLAGS) -o $(NAME)

clean	:
			rm -f $(NAME)

fclean	:	clean
			rm -f $(NAME)

rexport	:	fclean all

.PHONY	:	all clean fclean re