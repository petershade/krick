/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:50:13 by krick             #+#    #+#             */
/*   Updated: 2021/12/28 18:50:23 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd((char)s[i], fd);
		i++;
	}
}

int	ft_atoi2(long i, long a)
{
	if (i % 2 == 1)
		a *= -1;
	if (a < -2147483648 || a > 2147483647)
	{
		ft_putstr_fd ("Error\n", 1);
		exit(0);
	}
	return (a);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	a;

	i = 0;
	a = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		a = a + (*str - '0');
		a = a * 10;
		str++;
	}
	a = a / 10;
	return (ft_atoi2(i, a));
}

long int	time_get(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		error_write("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}
