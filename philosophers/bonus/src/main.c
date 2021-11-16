#include "philo.h"

void free_vars(t_philos *philos, pthread_t *th)
{
	free(philos);
	free(th);
}

int main(int argc, char **argv)
{
	t_info			info;
	t_philos 		*philos;
	pthread_t		*th;

	if (argc < 5 || argc > 6 || info_init(argc, argv, &info) == -1) //проверяем кол-во аргументов и
	{
		printf("/philo 6[philosophers] 400[eating] 200[eating] 100[sleeping] 5[meals]\n");
		return (1);
	}
	philos = malloc(sizeof(t_philos) * info.num_philo);
	if (!philos)
		return (malloc_error(&info));
	th = malloc(sizeof(pthread_t) * info.num_philo);
	if (!th)
		return (malloc_error(&info));
	philos_init(philos, &info);
//	forks_init(philos, forks, info.num_philo);
	threading_launching(philos, &info, th);
//	destroy_mutex(&info, forks);
	free_vars(philos, th);
	return (0);
}