/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:52:51 by krick             #+#    #+#             */
/*   Updated: 2021/12/28 17:53:50 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;

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

int	malloc_error(t_info *info)
{
	perror("philo");
	free(info->meals);
	return (1);
}
