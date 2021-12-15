#include "philo_bonus.h"

int	error_write(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	ft_life(t_info *info, int i)
{
	pthread_t	death;
	
	info->pids[i] = fork();
	if (info->philos[i].pid < 0)
	{
		write(2, "bad fork\n", 9);
		exit(0);
	}
	// printf("pids = %d, i = %d\n", info->pids[i], i);
	if (info->pids[i] == 0)
	{
		printf("pids = %d, i = %d\n", info->pids[i], i);
		if (i % 2)
			ft_sleep(10);
		if (pthread_create(&death, NULL, ft_death, &info->philos[i]))
			return (error_write("Pthread create error"));
		while (1)
			activity(&info->philos[i]);
		exit(0);
	}
	if (i == info->num_philo - 1)
		ft_wait(info);
	return (0);	
}

int	ft_semalloc(t_info *info)
{
	int	i;

	i = 0;
	info->pids = malloc(sizeof(pid_t) * info->num_philo);
	if (!info->pids)
		 return (error_write("Not malloced"));
	info->philos = malloc(sizeof(t_philos) * info->num_philo);
	if (!info->philos)
		return (error_write("Not malloced"));
	sem_unlink("/sema");
	info->sem_forks = sem_open("/sema", O_CREAT , 0666, info->num_philo);
	sem_unlink("/print");
	info->sem_msg = sem_open("/print", O_CREAT, 0666, 1);
	sem_unlink("/death");
	info->sem_stop = sem_open("/death", O_CREAT, 0666, 1);
	while (i < info->num_philo)
	{
		philos_init(info, i);
		ft_life(info, i);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_info		*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (error_write("Not malloced\n"));
	if ((argc <= 4 && argc >= 5) || info_init(argc, argv, info) == -1)
	{
		printf("/philo 6[philosophers] 400[eating] 200[eating] 100[sleeping] 5[meals]\n");
		return (1);
	}
	info->time_start = time_get();
	info->stop = 0;
	ft_semalloc(info);
	free(info);
	return (0);
}