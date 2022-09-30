/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:04:34 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 17:32:45 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool mo_construct(t_monitor *monitor, int argc, char **argv)
{
	int arguments[5];
	int	res;
	
	if (argc < 5 || argc > 6)
		return (false);
	int idx = 1;
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
	monitor->is_end = false;
	monitor->is_end_check = false;
	monitor->waiter_offset = 0;
	res = pthread_mutex_init(&monitor->speak, NULL);
    if (res == -1)
        return (false);
	res = pthread_mutex_init(&monitor->end, NULL);
    if (res == -1)
        return (false);
	res = pthread_mutex_init(&monitor->watier, NULL);
		if (res == -1)
			return (false);		
	return (true);
}

void mo_set_philos(t_monitor *monitor, t_philo **philos)
{
	monitor->philos = philos;
}

bool mo_start_philo(t_monitor *monitor)
{
	int 			i;
	int 			ret;
	unsigned long   time;
	
	time = get_current_time();
	i = 0;
	while (i < monitor->philo_num)
	{
		monitor->philos[i]->life_count = monitor->time_to_die;
		monitor->philos[i]->init_time = time;
		ret = pthread_create(&monitor->philos[i]->thread, NULL, &ph_activate_philo, monitor->philos[i]);
		if (ret != 0)
			return (false);
		i++;
	}
	return (true);
}

void	mo_check_philos(t_monitor *m)
{
	int             i;

    while (true)
	{
		pthread_mutex_lock(&m->end);
		if (m-> is_end == true)
		{
			pthread_mutex_unlock(&m->end);
			break ;
		}
		pthread_mutex_unlock(&m->end);
        
		i = 0;
		while (i < m->philo_num)
        {
			if (ph_is_dead(m->philos[i]))
			{
				ph_dead(m->philos[i]);
			}
			i++;
        }
		// pthread_mutex_lock(&info->fin_mtx);
		// if (info->meal_fin_num == info->philo_num)
		// {
		// 	pthread_mutex_unlock(&info->fin_mtx);
		// 	break ;
		// }
		// pthread_mutex_unlock(&info->fin_mtx);
    }
}