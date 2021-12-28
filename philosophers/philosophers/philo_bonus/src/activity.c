/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:20:58 by krick             #+#    #+#             */
/*   Updated: 2021/12/28 18:21:59 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(char *str, t_philos *philo)
{
	long int	time;

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
	while ((time_get() - start) < (long int)time)
		usleep(100);
}

void	ft_wait(t_info *info)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < info->num_philo)
	{
		waitpid(-1, &status, 0);
		i++;
		if (status)
		{
			i = 0;
			while (i < info->num_philo)
			{
				kill(info->pids[i], SIGKILL);
				i++;
			}
		}
	}
	free(info->pids);
	free(info->philos);
}

void	activity(t_philos *philo)
{
	sem_wait(philo->inf->sem_forks);
	ft_print("has taken a fork", philo);
	sem_wait(philo->inf->sem_forks);
	ft_print("has taken a fork", philo);
	ft_print("is eating", philo);
	philo->count++;
	philo->time_last_eat = time_get();
	ft_sleep(philo->inf->time_to_eat);
	sem_post(philo->inf->sem_forks);
	sem_post(philo->inf->sem_forks);
	ft_print("is sleeping", philo);
	ft_sleep(philo->inf->time_to_sleep);
	ft_print("is thinking", philo);
}
