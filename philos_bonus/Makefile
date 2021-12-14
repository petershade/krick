NAME		=	philo_bonus

SRCS		=	main.c \
				utils.c \
				death.c \
				activity.c \
				init.c \

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

CC			=	@gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	philo_bonus.h

RM			=	rm -rf

all:			$(NAME)

$(OBJS):		$(INCLUDES)

$(NAME): 		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "\033[30;42m      Program completed      "

clean:
				@${RM} $(OBJS)
				@echo "\033[30;43m        files deleted        "

fclean:			
				@${RM} $(OBJS) $(NAME)
				@echo "\033[30;43m        files deleted        "

re:				fclean all

.PHONY:			all clean fclean re