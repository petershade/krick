NAME				=	philo

SRCS_DIR			=	./src/

HEADER				=	./inc/philo.h

SRCS				=	main.c			\
						init.c			\
						utils.c			\
						thread.c		\
						time.c			\
						activity.c		\
						print.c			\
						error.c

SRCS_BASENAME		=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS				=	$(SRCS_BASENAME:.c=.o)

CC					=	@gcc

FLAGS				=	-Wall -Wextra -Werror -I ./inc/

.c.o			:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS) $(HEADER)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lpthread
				@echo [$(NAME)] : Created !

clean			:
				rm -f $(OBJS)
				@echo [.o] : Deleted !

fclean			:	clean
				rm -f $(NAME)
				@echo [$(NAME)] : Deleted !

re				:	fclean all

.PHONY: 		clean fclean all re