/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:04:28 by krick             #+#    #+#             */
/*   Updated: 2021/12/28 18:07:12 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_vars(t_philos *philos, pthread_t *th, pthread_mutex_t *forks)
{
	free(philos);
	free(th);
	free(forks);
}

int	main(int argc, char **argv)
{
	t_info			info;
	t_philos		*philos;
	pthread_t		*th;
	pthread_mutex_t	*forks;

	if (argc < 5 || argc > 6 || info_init(argc, argv, &info) == -1)
	{
		printf("/philo 6[philosophers] 400[die] 200[eat] 100[sleep] 5[meals]\n");
		return (1);
	}
	philos = malloc(sizeof(t_philos) * info.num_philo);
	if (!philos)
		return (malloc_error(&info));
	th = malloc(sizeof(pthread_t) * info.num_philo);
	if (!th)
		return (malloc_error(&info));
	forks = malloc(sizeof(pthread_mutex_t) * info.num_philo);
	if (!forks)
		return (malloc_error(&info));
	philos_init(philos, &info);
	forks_init(philos, forks, info.num_philo);
	threading_launching(philos, &info, th);
	destroy_mutex(&info, forks);
	free_vars(philos, th, forks);
	return (0);
}
