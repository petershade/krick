/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krick <krick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:23:53 by krick             #+#    #+#             */
/*   Updated: 2021/07/28 16:23:58 by krick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_arg	g_arg;

void	get_arg(int bit)
{
	g_arg.c = g_arg.c + ((bit & 1) << g_arg.size);
	g_arg.size++;
	if (g_arg.size == 8)
	{
		ft_putchar_fd(g_arg.c, 1);
		if (!g_arg.c)
			ft_putstr_fd("\n", 1);
		g_arg.c = 0;
		g_arg.size = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_arg.c = 0;
	g_arg.size = 0;
	pid = getpid();
	if (pid != 0)
	{
		ft_putstr_fd("pid : ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		ft_putstr_fd("Ah Shit, here we go again", 1);
	while (1)
	{
		signal(SIGUSR2, get_arg);
		signal(SIGUSR1, get_arg);
		pause();
	}
}
