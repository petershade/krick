int main(int argc, char **argv)
{
	t_info			info;

	if (argc < 5 || argc > 6 || info_init(argc, argv, &info) == -1);
	{
		printf("/philo 6[philosophers] 400[eating] 200[eating] 100[sleeping] 5[meals]\n");
		return (1);
	}
	philos = malloc(sizeof(t_philos) * info.num_philo);
	if (!philos)
		return (malloc_error(&info));
	philos_init(philos, &info);
}