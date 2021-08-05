NAME   = libftprintf.a

INCLUDES = sources/ft_printf.h

SRCS = ft_printf.c\
		sources/ft_flags.c\
		sources/ft_start.c\
		sources/print_char.c\
		sources/print_str.c\
		sources/print_di.c\
		sources/print_di_neg.c\
		sources/print_u.c\
		sources/print_x.c\
		sources/print_xx.c\
		sources/print_p.c\

OBJS  = ${SRCS:.c=.o}

CC   = gcc

RM   = rm -f

CFLAGS  = -Wall -Wextra -Werror -I.

%.o : %.c $(INCLUDES)
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:  ${OBJS}
	ar rcs ${NAME} ${OBJS}

all:  ${NAME}

clean:
	${RM} ${OBJS}

fclean:  clean
	${RM} ${NAME}

re:   fclean all

.PHONY:  all clean fclean re