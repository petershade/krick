#include "philo.h"

void	right_handed(t_philos *philos)
{
	sem_wait(philos->info->sem_forks);
//	pthread_mutex_lock(philos->right_fork);
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	if (philos->num == 1)
	{
		sem_post(philos->info->sem_forks);
//		pthread_mutex_unlock(philos->right_fork);
		ft_usleep(philos->ttd);
		return ;
	}
	sem_wait(philos->info->sem_forks);
//	pthread_mutex_lock(philos->left_fork);
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is_eating");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	philos->count++;
	sem_wait(philos->info->sem_last_eat);
//	pthread_mutex_lock(&philos->info->mutex_last_eat);
	philos->time_last_eat = get_time();
	sem_post(philos->info->sem_last_eat);
//	pthread_mutex_unlock(&philos->info->mutex_last_eat);
	ft_usleep(philos->tte);
	sem_post(philos->info->sem_forks);
//	pthread_mutex_unlock(philos->right_fork);
	sem_post(philos->info->sem_forks);
//	pthread_mutex_unlock(philos->left_fork);
}

void left_handed(t_philos *philos)
{
	sem_wait(philos->info->sem_forks);
//	pthread_mutex_lock(philos->right_fork);
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	if (philos->num == 1)
	{
		sem_post(philos->info->sem_forks);
//		pthread_mutex_unlock(philos->right_fork);
		ft_usleep(philos->ttd);
		return ;
	}
	sem_wait(philos->info->sem_forks);
//	pthread_mutex_lock(philos->right_fork);
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is eating");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	philos->count++;
	sem_wait(philos->info->sem_last_eat);
//	pthread_mutex_lock(&philos->info->mutex_last_eat);
	philos->time_last_eat = get_time();
	sem_post(philos->info->sem_last_eat);
//	pthread_mutex_unlock(&philos->info->mutex_last_eat);
	ft_usleep(philos->tte);
	sem_post(philos->info->sem_forks);
//	pthread_mutex_unlock(philos->left_fork);
	sem_post(philos->info->sem_forks);
//	pthread_mutex_unlock(philos->right_fork);
}

void eat_activity(t_philos *philos)
{
	if (philos->id % 2 == 0)
		right_handed(philos);
	else
		left_handed(philos);
}

void activity(t_philos *philos)
{
	eat_activity(philos);
	if (philos->num_meals != -1 && philos->count > philos->num_meals)
	{
		sem_wait(philos->info->sem_stop);
//		pthread_mutex_lock(&philos->info->mutex_stop);
		philos->stop = 1;
		sem_post(philos->info->sem_stop);
//		pthread_mutex_unlock(&philos->info->mutex_stop);
		return ;
	}
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is sleeping");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	ft_usleep(philos->tts);
	sem_wait(philos->info->sem_msg);
//	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is thinking");
	sem_post(philos->info->sem_msg);
//	pthread_mutex_unlock(&philos->info->mutex_msg);
	if (philos->num % 2 != 0)
		ft_usleep(100);
}