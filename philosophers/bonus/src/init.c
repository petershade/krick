#include "philo.h"

int info_init(int argc, char **argv, t_info *info)
{
	if (check_error(argc, argv) == -1)
		return (-1);
	info->num_philo = (int)ft_atoi(argv[1]);
	info->time_to_die = (unsigned int)ft_atoi(argv[2]);
	info->time_to_eat = (unsigned int)ft_atoi(argv[3]);
	info->time_to_sleep = (unsigned int)ft_atoi(argv[4]);
	if (argc == 6)
		info->num_meals = (int)ft_atoi(argv[5]);
	else
		info->num_meals = -1;
	info->stop = 0;
//	pthread_mutex_init(&info->mutex_stop, NULL);
//	pthread_mutex_init(&info->mutex_msg, NULL);
//	pthread_mutex_init(&info->mutex_last_eat, NULL);
	return (0);
}

void philos_init(t_philos *philos, t_info *info)
{
	int i;

	i = 0;
	while (i < info->num_philo)
	{
		philos[i].info = info;
		philos[i].id = i + 1;
		philos[i].num = info->num_philo;
		philos[i].count = 0;
		philos[i].stop = 0;
		philos[i].ttd = info->time_to_die;
		philos[i].tte = info->time_to_eat;
		philos[i].tts = info->time_to_sleep;
		philos[i].num_meals = info->num_meals;
		i++;
	}
}

//void forks_init(t_philos *philos, pthread_mutex_t *forks, int num)
//{
//	int i;
//
//	pthread_mutex_init(&forks[0], NULL);
//	philos[0].left_fork = &forks[0];
//	philos[0].right_fork = NULL;
//	philos[0].right_fork = &forks[num - 1];
//	i = 1;
//	while (i < num)
//	{
//		pthread_mutex_init(&forks[i], NULL);
//		philos[i].left_fork = &forks[i];
//		philos[i].right_fork = &forks[i - 1];
//		i++;
//	}
//}