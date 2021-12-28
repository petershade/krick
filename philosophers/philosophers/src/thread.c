/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:08:04 by krick             #+#    #+#             */
/*   Updated: 2021/12/28 18:09:06 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_dead(void *arg)
{
	t_philos	*philos;
	int			stop;

	philos = (t_philos *)arg;
	stop = 0;
	while (!stop)
	{
		pthread_mutex_lock(&philos->info->mutex_last_eat);
		if (get_time() - philos->time_last_eat >= philos->ttd)
		{
			pthread_mutex_unlock(&philos->info->mutex_last_eat);
			pthread_mutex_lock(&philos->info->mutex_msg);
			print_status(philos, "died");
			pthread_mutex_unlock(&philos->info->mutex_msg);
		}
		else
			pthread_mutex_unlock(&philos->info->mutex_last_eat);
		pthread_mutex_lock(&philos->info->mutex_stop);
		stop = philos->info->stop + philos->stop;
		philos->info->stop = stop;
		pthread_mutex_unlock(&philos->info->mutex_stop);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philos	*philos;
	int			stop;

	philos = (t_philos *)arg;
	philos->time_last_eat = philos->info->time_start;
	if (pthread_create(&philos->faucheuse, NULL, &is_dead, philos))
		perror("pthread_create failed");
	pthread_detach(philos->faucheuse);
	stop = 0;
	while (!stop)
	{
		activity(philos);
		pthread_mutex_lock(&philos->info->mutex_stop);
		stop = philos->info->stop + philos->stop;
		pthread_mutex_unlock(&philos->info->mutex_stop);
	}
	return (NULL);
}

int	threading_launching(t_philos *philos, t_info *info, pthread_t *th)
{
	int	i;

	i = 0;
	info->time_start = get_time();
	while (i < info->num_philo)
	{
		if (pthread_create(&th[i], NULL, &routine, &philos[i]))
			perror("pthread_create failed");
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(th[i], NULL))
			perror("join failed");
		i++;
	}
	return (0);
}

void	destroy_mutex(t_info *info, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->mutex_last_eat);
	pthread_mutex_destroy(&info->mutex_msg);
	pthread_mutex_destroy(&info->mutex_stop);
}
