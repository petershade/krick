/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:22:15 by krick             #+#    #+#             */
/*   Updated: 2021/12/28 18:23:52 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_death(t_philos *ph)
{
	if (ph->count > ph->inf->num_meals && ph->inf->num_meals != -1)
		ph->inf->meals++;
	if (ph->inf->time_to_die < time_get() - ph->time_last_eat)
	{
		sem_wait(ph->inf->sem_stop);
		sem_wait(ph->inf->sem_msg);
		printf("%ld Philo %d is died\n", time_get() - ph->time_last_eat, \
		ph->id);
		exit(1);
		sem_post(ph->inf->sem_stop);
	}
	return (0);
}

void	*ft_death(void *philo)
{
	t_philos	*ph;

	ph = (t_philos *)philo;
	ph->inf->meals = 0;
	while (1)
	{
		if (check_death(ph))
			return (NULL);
		if (ph->inf->meals >= ph->inf->num_philo)
		{
			ft_sleep(ph->inf->time_to_eat);
			exit(1);
			return (NULL);
		}
	}
	return (NULL);
}
