#include "philo.h"

unsigned int get_time(void)
{
	unsigned int 	ret;
	struct timeval	time;

	ret = 0;
	if (gettimeofday(&time, NULL) == -1)
	{
		perror("gettimeofday() failed");
		return (0);
	}
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);

}

void	ft_usleep(unsigned int time_in_ms)
{
	unsigned int start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(70);
		//usleep(time_in_ms / 10);
}