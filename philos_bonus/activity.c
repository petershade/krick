#include "philo_bonus.h"

void    ft_print(char *str, t_philos *philo)
{
	unsigned int	time;

	time = time_get() - philo->inf->time_start;
	sem_wait(philo->inf->sem_msg);
	printf("%ld Philo %d %s\n", time, philo->id, str);
	if (!philo->inf->stop)
		sem_post(philo->inf->sem_msg);
}

void	ft_sleep(int time)
{
	long int	start;

	start = time_get();
	while ((time_get()- start) < (long int)time)
		usleep(100);
}

void    activity(t_philos *philo)
{
	sem_wait(philo->inf->sem_forks);
	ft_print("has taken a fork", philo);
	sem_wait(philo->inf->sem_forks);
	ft_print("has taken a fork", philo);
	ft_printf("is eating", philo);
	philo->count++;
	philo->time_last_eat = time_get();
	ft_sleep(philo->inf->time_to_eat);
	sem_post(philo->inf->sem_forks);
	sem_post(philo->inf->sem_forks);
	ft_printf("is sleeping", philo);
	ft_sleep(philo->inf->time_to_sleep);
	ft_printf("is thinking", philo);
}