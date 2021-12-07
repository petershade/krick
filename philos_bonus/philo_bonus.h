#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>
# include <semaphore.h>

typedef struct s_philos	t_philos;

typedef struct	s_info
{
	int 			num_philo;
	unsigned int 	time_to_die;
	unsigned int 	time_to_eat;
	unsigned int 	time_to_sleep;
	unsigned int	time_start;
	int 			num_meals; //количество раз который должен поесть философ
	int 			meals;
	int 			stop;
	sem_t			*sem_forks;
	sem_t			*sem_msg;
	sem_t			*sem_stop;
	t_philos		*philos;
	pid_t			*pids
}					t_info;

typedef struct s_philos
{
	t_info			*inf;
	int 			id;
	int 			num;
	int 			count;
	int 			num_meals;
	unsigned int 	time_last_eat;
	pthread_t 		faucheuse;
	pid_t			*pid;
}				t_philos;

int 	info_init(int argc, char **argv, t_info *info);
int		error_write(char *str);
void	ft_semalloc(t_info *info);
void 	philos_init(t_info *info, int	i);

#endif