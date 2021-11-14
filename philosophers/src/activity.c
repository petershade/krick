#include "philo.h"

void	right_handed(t_philos *philos)
{
	pthread_mutex_lock(philos->right_fork);
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	if (philos->num == 1)
	{
		pthread_mutex_unlock(philos->right_fork);
		ft_usleep(philos->ttd);
		return ;
	}
	pthread_mutex_lock(philos->left_fork);
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is_eating");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	philos->count++;
	pthread_mutex_lock(&philos->info->mutex_last_eat);
	philos->time_last_eat = get_time();
	pthread_mutex_unlock(&philos->info->mutex_last_eat);
	ft_usleep(philos->tte);
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(philos->left_fork);
}

void left_handed(t_philos *philos)
{
	pthread_mutex_lock(philos->left_fork);
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	if (philos->num == 1)
	{
		pthread_mutex_unlock(philos->left_fork);
		ft_usleep(philos->ttd);
		return ;
	}
	pthread_mutex_lock(philos->right_fork);
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "has taken a fork");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is eating");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	philos->count++;
	pthread_mutex_lock(&philos->info->mutex_last_eat);
	philos->time_last_eat = get_time();
	pthread_mutex_unlock(&philos->info->mutex_last_eat);
	ft_usleep(philos->tte);
	pthread_mutex_unlock(philos->left_fork);
	pthread_mutex_unlock(philos->right_fork);
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
		pthread_mutex_lock(&philos->info->mutex_stop);
		philos->stop = 1;
		pthread_mutex_unlock(&philos->info->mutex_stop);
		return ;
	}
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is sleeping");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	ft_usleep(philos->tts);
	pthread_mutex_lock(&philos->info->mutex_msg);
	print_status(philos, "is thinking");
	pthread_mutex_unlock(&philos->info->mutex_msg);
	if (philos->num % 2 != 0)
		ft_usleep(100);
}