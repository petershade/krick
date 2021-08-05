NAME = libft.a

LIST	= ft_atoi.c\
			ft_putchar_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_strlen.c

OBJS 	= $(LIST:.c=.o)
FLAGS	= -Wall -Wextra -Werror

.o:.c
			gcc $(FLAGS) -c $< -o (<:.c=.o) -I .

all: 		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			rm -rf $(OBJS)

fclean: 	clean
			rm -rf $(NAME)

re:
			fclean all

.PHONY: 	all clean fclean re