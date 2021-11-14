#include "philo.h"

void	*is_dead(void *arg)
{
	t_philos	*philos;
	int			stop;

	philos = (t_philos *)arg;
	stop = 0;
	while (!stop)
	{
		sem_wait(info->sem_last_eat);
//		pthread_mutex_lock(&philos->info->mutex_last_eat);
		if (get_time() - philos->time_last_eat >= philos->ttd)
		{
			sem_post(info->sem_last_eat);
//			pthread_mutex_unlock(&philos->info->mutex_last_eat);
			sem_wait(info->sem_msg);
//			pthread_mutex_lock(&philos->info->mutex_msg);
			print_status(philos, "died");
			sem_post(info->sem_msg);
//			pthread_mutex_unlock(&philos->info->mutex_msg);
		}
		else
			pthread_mutex_unlock(&philos->info->mutex_last_eat);
		sem_wait(info->stop);
//		pthread_mutex_lock(&philos->info->mutex_stop);
		stop = philos->info->stop + philos->stop;
		philos->info->stop = stop;
		sem_post(info->sem_stop);
//		pthread_mutex_unlock(&philos->info->mutex_stop);
	}
	return (NULL);
}

void *routine(void *arg)
{
	t_philos	*philos;
	int 		stop;

	philos = (t_philos *)arg;
	philos->time_last_eat = philos->info->time_start;
	if (pthread_create(&philos->faucheuse, NULL, &is_dead, philos))
		perror("pthread_create failed");
	pthread_detach(philos->faucheuse);
	stop = 0;
	while (!stop)
	{
		activity(philos);
		sem_wait(info->sem_stop);
//		pthread_mutex_lock(&philos->info->mutex_stop);
		stop = philos->info->stop + philos->stop;
		sem_post(info->sem_stop);
//		pthread_mutex_unlock(&philos->info->mutex_stop);
	}
	return (NULL);
}

void sem_init(t_info *info)
{
	sem_unlink("/forks");
	info->forks = sem_open("/forks", O_CREAT, 0666, info->num_philo);
	sem_unlink("/message");
	info->forks = sem_open("/message", O_CREAT, 0666, 1);
	sem_unlink("/death");
	info->forks = sem_open("/death", O_CREAT, 0666, 1);
}

void ft_life(t_philos *philos, t_info *info)
{
//	philos->pid[philos->id] = fork();
	info->pid[philos->id] = fork();
	if (info->pid[philos->id] == 0)
	{
		routine(philos);
	}
}

int threading_launching(t_philos *philos, t_info *info, pthread_t *th)
{
	int i;

	i = 0;
	info->time_start = get_time();
	sem_init(info);
	while (i < info->num_philo)
	{
		ft_life(&philos[i], info);
//		if (pthread_create(&th[i], NULL, &routine, &philos[i]))
//			perror("pthread_create failed");
//		i++;
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

void destroy_mutex(t_info *info, pthread_mutex_t *forks)
{
	int i;

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