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
		philos[i].num_meals = info->num_meals;
		i++;
	}
}