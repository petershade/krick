NAME	= push_swap

SRC		= main.c \
		error.c \
		libft.c \
		list.c \
		commands.c \
		commands1.c \
		quicksort.c

OBJ		= $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror -g

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			cc $(OBJ) $(CFLAGS) -o $(NAME)

clean	:
			rm -f $(NAME) $(OBJ)

fclean	:	clean
			rm -f $(NAME) 

re	:	fclean all

.PHONY	:	all clean fclean re