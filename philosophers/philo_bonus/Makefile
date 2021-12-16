NAME				=	philo_bonus

SRCS_DIR			=	./src/

HEADER				=	./inc/philo_bonus.h

SRCS				=	main.c \
						utils.c \
						death.c \
						activity.c \
						init.c \

SRCS_BASENAME		=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS				=	$(SRCS_BASENAME:.c=.o)

CC					=	@gcc

FLAGS				=	-Wall -Wextra -Werror -I ./inc/

.c.o				:
					$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all					:	$(NAME)

$(NAME)				:	$(OBJS) $(HEADER)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lpthread
					@echo "\033[30;42m      [$(NAME)] : Created !      "

clean				:
					@rm -f $(OBJS)
					@echo "\033[30;43m        [.o] : Deleted !        "

fclean				:
					@rm -f $(NAME) $(OBJS)
					@echo "\033[30;43m        [Program] : Deleted !        "

re					:	fclean all

.PHONY: 			clean fclean all re