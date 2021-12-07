#include "philo_bonus.h"

int	error_write(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int malloc_error(t_info *info)
{
	perror("philo");
	free(info->meals);
	return (1);
}

int	ft_life(t_info *info, int i)
{
	pthread_t	death;

	info->pids[i] = forks();
	if (info->philos[i].pid < 0)
	{
		write(2, "bad fork\n", 9);
		exit(0);
	}
	if (info->pids[i] == 0)
	{
		if (i % 2)
			ft_sleep(10);
		if (pthread_create(&death, NULL, ft_death, &info->philos[i]))
			return (error_write("Pthread create error"));
		while (1)
			activity(&info->philos[i]);
		exit(0);
	}
	
}

void	ft_semalloc(t_info *info)
{
	info->pids = malloc(sizeof(pid_t) * info->num_philo);
	if (!info->pids)
		 return (malloc_error(&info));
	info->philos = malloc(sizeof(t_philos) * info->num_philo);
	if (!info->philos)
		return (malloc_error(&info));
	info->sem_forks = sem_open("/sema", O_CREAT, 0666, info->num_philo);
	sem_unlink("/print");
	info->sem_msg = sem_open("/print", O_CREAT, 0666, 1);
	sem_unlink("/death");
	info->sem_stop = sem_open("/death", O_CREAT, 0666, 1);
}

int main(int argc, char **argv)
{
	int			i;
	t_info		*info;
	t_philos	*philos;

	i = 0;
	if (argc < 5 || argc > 6 || info_init(argc, argv, &info) == -1);
	{
		printf("/philo 6[philosophers] 400[eating] 200[eating] 100[sleeping] 5[meals]\n");
		return (1);
	}
	info->time_start = time_get();
	ft_semalloc(info);
	while (i < info->num_philo)
	{
		philos_init(info, i);
		ft_life(info, i);
		i++;
	}
	free(info);
	return (0);
}