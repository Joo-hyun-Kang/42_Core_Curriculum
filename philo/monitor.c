/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:04:34 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 21:07:24 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	mo_construct(t_monitor *monitor, int argc, char **argv)
{
	int	arguments[5];
	int	idx;

	if (argc < 5 || argc > 6)
		return (false);
	idx = 1;
	while (idx < argc)
	{
		arguments[idx - 1] = ft_atoi(argv[idx]);
		if (arguments[idx - 1] <= 0)
			return (false);
		idx++;
	}
	monitor->philo_num = arguments[0];
	monitor->time_to_die = arguments[1];
	monitor->time_to_eat = arguments[2];
	monitor->time_to_sleep = arguments[3];
	if (argc == 6)
		monitor->count_must_eat = arguments[4];
	else
		monitor->count_must_eat = -1;
	if (mo_construct_helper(monitor) == false)
		return (false);
	return (true);
}

bool	mo_construct_helper(t_monitor *monitor)
{
	int	res;

	monitor->is_end = false;
	monitor->is_end_check = false;
	monitor->waiter_offset = 0;
	monitor->finish_philos = 0;
	res = pthread_mutex_init(&monitor->speak, NUL);
	if (res == -1)
		return (false);
	res = pthread_mutex_init(&monitor->end, NUL);
	if (res == -1)
		return (false);
	res = pthread_mutex_init(&monitor->watier, NUL);
	if (res == -1)
		return (false);
	res = pthread_mutex_init(&monitor->must, NUL);
	if (res == -1)
		return (false);
	return (true);
}

void	mo_set_philos(t_monitor *monitor, t_philo **philos)
{
	monitor->philos = philos;
}

bool	mo_start_philo(t_monitor *monitor)
{
	int				i;
	int				ret;
	unsigned long	time;

	time = get_current_time();
	i = 0;
	while (i < monitor->philo_num)
	{
		monitor->philos[i]->life_count = monitor->time_to_die;
		monitor->philos[i]->init_time = time;
		ret = pthread_create(&monitor->philos[i]->thread, NUL, \
		&ph_activate_philo, monitor->philos[i]);
		if (ret != 0)
			return (false);
		i++;
	}
	return (true);
}

void	mo_check_philos(t_monitor *m)
{
	int	i;

	while (true)
	{
		pthread_mutex_lock(&m->end);
		if (m-> is_end == true)
		{
			pthread_mutex_unlock(&m->end);
			break ;
		}
		pthread_mutex_unlock(&m->end);
		i = -1;
		while (++i < m->philo_num)
		{
			if (ph_is_dead(m->philos[i]))
				ph_dead(m->philos[i]);
		}
		pthread_mutex_lock(&m->must);
		if (m->philo_num == m->finish_philos)
		{
			pthread_mutex_unlock(&m->must);
			break ;
		}
		pthread_mutex_unlock(&m->must);
	}
}
