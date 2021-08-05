NAME1 = server

NAME2 = client


CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all:
		make -C libft
		$(CC) $(CFLAGS) server.c libft/libft.a -o $(NAME1)
		$(CC) $(CFLAGS) client.c libft/libft.a -o $(NAME2)

clean :
		make clean -C libft
		$(RM) client.o server.o

fclean: clean
		make fclean -C libft
		$(RM) $(NAME1) $(NAME2)

re: fclean all