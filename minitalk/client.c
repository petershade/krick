/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:24:31 by krick             #+#    #+#             */
/*   Updated: 2021/07/28 16:24:34 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_zerone(int pid, char *str, int len)
{
	int	i;
	int	moving;

	i = 0;
	while (i <= len)
	{
		moving = 0;
		while (moving <= 7)
		{
			if ((str[i] >> moving) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			moving++;
			usleep(30);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_zerone(pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_putstr_fd("./client [pid] [msg]\n", 1);
	return (0);
}
