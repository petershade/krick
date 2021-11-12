#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

typedef struct	s_info
{
	int 			num_philo;
	unsigned int 	time_to_die;
	unsigned int 	time_to_eat;
	unsigned int 	time_to_sleep;
	unsigned int	time_start;
	int 			num_meals;
	int 			*meals;
	int 			stop;
	pthread_mutex_t mutex_stop;
	pthread_mutex_t mutex_msg;
	pthread_mutex_t mutex_last_eat;
}					t_info;

typedef struct s_philos
{
	t_info			*info;
	int 			id;
	int 			num;
	int 			count;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int 	tts;
	int 			num_meals;
	unsigned int 	time_last_eat;
	int 			stop;
	pthread_t 		faucheuse;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t *left_fork;
}				t_philos;

int 			ft_isdigit(int c);
int 			ft_strlen(char *str);
int				ft_strcmp(const char *str1, const char *str2);
long 			ft_atoi(char *str);
unsigned int	get_time(void);
void			ft_usleep(unsigned int time_in_ms);
int 			check_error(int argc, char **argv);
int 			malloc_error(t_info *info);
int				itoa_len(long nb);
char			*ft_itoa(int num);
char			*ft_strcat(char *dest, char *src);
int				create_string(t_philos *philos, char *status, char **str);
void			print_status(t_philos *philos, char *status);
void			*is_dead(void *arg);
void 			*routine(void *arg);
int 			threading_launching(t_philos *philos, t_info *info, pthread_t *th);
void 			destroy_mutex(t_info *info, pthread_mutex_t *forks);
void			right_handed(t_philos *philos);
void 			left_handed(t_philos *philos);
void 			eat_activity(t_philos *philos);
void 			activity(t_philos *philos);
int 			info_init(int argc, char **argv, t_info *info);
void			philos_init(t_philos *philos, t_info *info);
void 			forks_init(t_philos *philos, pthread_mutex_t *forks, int num);
void 			free_vars(t_philos *philos, pthread_t *th, pthread_mutex_t *forks);

#endif