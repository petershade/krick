#include "philo_bonus.h"

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int check_error(int argc, char **argv)
{
	int 	i;
	int 	j;
	long 	num;

	i = 0;
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > 2147483647 || num == 0)
			return (-1);
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
		}
	}
	return (0);
}

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

void philos_init(t_info *info, int	i)
{
	info->philos[i].inf = info;
	info->philos[i].count = 0;
	info->philos[i].id = i + 1;
	info->philos[i].time_last_eat = time_get();

}