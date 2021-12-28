/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:07:35 by krick             #+#    #+#             */
/*   Updated: 2021/12/28 18:07:40 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	itoa_len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*str;
	long	nb;
	int		i;

	nb = num;
	i = itoa_len(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	create_string(t_philos *philos, char *status, char **str)
{
	char	*strs[3];
	int		lenres;
	int		i;

	strs[0] = ft_itoa((int)(get_time() - philos->info->time_start));
	strs[1] = ft_itoa(philos->id);
	strs[2] = status;
	lenres = ft_strlen(strs[0]) + ft_strlen(strs[1]) + ft_strlen(strs[2]) + 4;
	*str = malloc(lenres);
	*str[0] = '\0';
	i = 0;
	while (i < 3)
	{
		ft_strcat(*str, strs[i]);
		if (i < 2)
		{
			ft_strcat(*str, " ");
			free(strs[i]);
		}
		i++;
	}
	ft_strcat(*str, "\n");
	return (lenres);
}

void	print_status(t_philos *philos, char *status)
{
	char	*str;
	int		len;

	pthread_mutex_lock(&philos->info->mutex_stop);
	if (philos->info->stop == 1)
	{
		pthread_mutex_unlock(&philos->info->mutex_stop);
		return ;
	}
	if (!ft_strcmp(status, "died"))
		philos->info->stop = 1;
	pthread_mutex_unlock(&philos->info->mutex_stop);
	len = create_string(philos, status, &str);
	write(1, str, len);
	free(str);
}
