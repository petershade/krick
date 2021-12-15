#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <semaphore.h>

typedef struct s_philos	t_philos;

typedef struct	s_info
{
	int 			num_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		time_start;
	int 			num_meals; //количество раз который должен поесть философ
	int 			meals;
	int 			stop;
	sem_t			*sem_forks;
	sem_t			*sem_msg;
	sem_t			*sem_stop;
	t_philos		*philos;
	pid_t			*pids;
}					t_info;

typedef struct s_philos
{
	t_info			*inf;
	int 			id;
	int 			num;
	int 			count;
	long int 		time_last_eat;
	pthread_t 		faucheuse;
	pid_t			*pid;
}				t_philos;

int			error_write(char *str);
int 		malloc_error(t_info *info);
int			ft_life(t_info *info, int i);
int			ft_semalloc(t_info *info);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi2(long i, long a);
int			ft_atoi(const char *str);
long int	time_get(void);
int 		ft_isdigit(int c);
int 		check_error(int argc, char **argv);
int 		info_init(int argc, char **argv, t_info *info);
void 		philos_init(t_info *info, int	i);
int 		check_death(t_philos *ph);
void    	*ft_death(void *philo);
void    	ft_print(char *str, t_philos *philo);
void		ft_sleep(int time);
void    	activity(t_philos *philo);
void		ft_wait(t_info *info);

#endif