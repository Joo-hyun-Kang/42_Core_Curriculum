/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:15:24 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 21:07:24 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ph_construct(t_philo **philo, int id, t_monitor *m)
{	
	int	ret;

	(*philo) = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NUL)
		return (false);
	(*philo)->id = id;
	(*philo)->philo_num = m->philo_num;
	(*philo)->time_to_die = m->time_to_die;
	(*philo)->time_to_sleep = m->time_to_sleep;
	(*philo)->time_to_eat = m->time_to_eat;
	(*philo)->count_must_eat = m->count_must_eat;
	(*philo)->eat_count = 0;
	(*philo)->left = m->forks[id];
	(*philo)->right = m->forks[(id + 1) % m->philo_num];
	(*philo)->status = NONE;
	(*philo)->monitor = m;
	ret = pthread_mutex_init(&(*philo)->life, NUL);
	if (ret == -1)
		return (false);
	ret = pthread_mutex_init(&(*philo)->status_mtx, NUL);
	if (ret == -1)
		return (false);
	return (true);
}

void	*ph_activate_philo(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->philo_num == 1)
	{
		up_fork_alone(p);
		return (NUL);
	}
	if (ph_is_thinker(p))
		ph_wait(p);
	while (true)
	{
		if (ph_is_waiter(p))
			ph_spend(p, p->time_to_eat);
		up_fork(p);
		ph_eat(p);
		down_fork(p);
		if (ph_count_must_eat(p))
			break ;
		ph_sleep(p);
		ph_think(p);
		if (ph_check_monitor(p))
			break ;
	}
	return (NUL);
}

bool	ph_is_waiter(t_philo *philo)
{
	t_monitor	*m;
	int			waiter_count;
	int			waiter;
	bool		ret;

	if (philo->philo_num % 2 != 1)
		return (false);
	m = philo->monitor;
	ret = false;
	pthread_mutex_lock(&m->watier);
	waiter_count = philo->philo_num - 1 + m->waiter_offset;
	waiter = waiter_count % philo->philo_num;
	if (philo->id == waiter)
	{
		m->waiter_offset++;
		ret = true;
	}
	pthread_mutex_unlock(&m->watier);
	return (ret);
}

bool	ph_is_thinker(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		if (philo->id % 2 == 1)
			return (true);
	}
	if (philo->philo_num % 2 == 1)
	{
		if (philo->id % 2 == 1)
			return (true);
		if (philo->id == philo->philo_num - 1)
			return (true);
	}
	return (false);
}

bool	ph_count_must_eat(t_philo *p)
{
	if (p->eat_count == p->count_must_eat)
	{
		pthread_mutex_lock(&p->monitor->must);
		p->monitor->finish_philos++;
		pthread_mutex_unlock(&p->monitor->must);
		return (true);
	}
	return (false);
}
