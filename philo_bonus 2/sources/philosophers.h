 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:43:46 by wroyal            #+#    #+#             */
/*   Updated: 2021/11/04 18:46:25 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					cnt_of_ph; //количество философов
	int					tm_to_die; //время для смерти
	int					tm_to_eat; //время для еды
	int					tm_to_sleep; //время для сна
	int					must_eat; //количество раз который должен поесть философ
	int					counter; //счётчик философов которые поели must_eat раз
	int					dead_flag; //остановка
	t_philo				*ph; //философ
	long int			start_time; //начало жизни философов
	pid_t				*pids_mas; //массив пидов
	sem_t				*sem_frk; //семафоры
	sem_t				*sem_wrt;
	sem_t				*sem_dth;
}						t_data;

typedef struct s_philo
{
	int					ph_id; //id философа
	int					eat_tm; //время на поесть
	int					slp_tm; //время на поспать
	int					cnt_eat; //сколько раз поел философ
	long int			life; //время последнего приёма пищи
	t_data				*das; //ссылка на другую структуру
	pthread_t			thread; //трэд для того чтобы проверять философов на смерть
	pid_t				pid; //pid философа
}						t_philo;

long int	time_get(void);
void		ft_sleep(int time);
void		*ft_dead(void *das);
int			ft_error(char *str);
void		activity(t_philo *ph);
int			check_args(char *str);
void		ft_wait(t_data *data);
int			philo_make(t_data *data);
int			ft_atoi(const char *str);
void		*philosophing(void	*das);
int			ft_shield(long i, long a);
int			check_death_dop(t_philo *ph);
int			ft_life(t_data *data, int i);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_print(char *str, t_philo *ph);
void		init_philo(t_data *data, int ind);
int			args_pars(int argc, char **argv, t_data *data);

#endif
