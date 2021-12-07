#include "philo_bonus.h"

int check_death(t_philo *ph)
{
    if (ph->num_philo > ph->inf->num_philo && ph->inf->)
}

void    *ft_death(void *philo)
{
    t_philos *ph;

    ph = (t_philos *)philo;
    ph->inf->meals = 0;
    while (1)
    {
        if (check_death(ph))
            return (NULL);
        if (ph->inf->meals >= ph->inf->num_philo)
        {
            ft_sleep(ph->inf->time_to_eat);
            exit(1);
            return (NULL);
        }
    }
    return (NULL);
}
