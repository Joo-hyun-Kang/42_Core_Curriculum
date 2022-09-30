/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:15:24 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 17:18:54 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool ph_construct(t_philo **philo, int id, t_monitor *m)
{	
	int ret;
	
	(*philo) = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		return (false);
	(*philo)->id = id;
	(*philo)->philo_num = m->philo_num;
	(*philo)->time_to_die = m->time_to_die;
	(*philo)->time_to_sleep = m->time_to_sleep;
	(*philo)->time_to_eat = m->time_to_eat;
	(*philo)->eat_count = 0;
	(*philo)->left = m->forks[id];
	(*philo)->right = m->forks[(id + 1) % m->philo_num];
	(*philo)->status = NONE;
	(*philo)->monitor = m;
	ret = pthread_mutex_init(&(*philo)->life, NULL);
    if (ret == -1)
        return (false);
	ret = pthread_mutex_init(&(*philo)->status_mtx, NULL);
    if (ret == -1)
        return (false);
	return (true);
}

void	*ph_activate_philo(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	if (p->philo_num == 1)
	{
		up_fork_alone(p);
		return (NULL);
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
		ph_sleep(p);
		ph_think(p);
		if (ph_check_monitor(p))
			break;
	}
	return (NULL);
}

bool ph_is_waiter(t_philo *philo)
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

bool ph_is_thinker(t_philo *philo)
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

void ph_wait(t_philo *philo)
{
	philo->status = THINK;
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_eat);
}

void ph_think(t_philo *philo)
{
	philo->status = THINK;
	ph_print_state(philo);
}

void ph_eat(t_philo *philo)
{
	unsigned long init_to_eat;
	
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = EAT;
	pthread_mutex_unlock(&philo->status_mtx);
	init_to_eat = get_current_time() - philo->init_time;
	pthread_mutex_lock(&philo->life);
	philo->life_count = init_to_eat + philo->time_to_die;
	pthread_mutex_unlock(&philo->life);
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_eat);
}

void ph_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = SLEEP;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_sleep);
}

void	up_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	philo->status = FORK;
	ph_print_state(philo);
	pthread_mutex_lock(&philo->right);
	philo->status = FORK;
	ph_print_state(philo);
}

void	up_fork_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	philo->status = FORK;
	ph_print_state(philo);

	while (!ph_is_dead(philo))
	{
	}
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = DEATH;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	pthread_mutex_unlock(&philo->left);
}


void	down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(&philo->right);
	philo->eat_count += 1;
}

void ph_spend(t_philo *philo, unsigned long time)
{
	unsigned long	start;
	unsigned long	current;
	int				is_dead;

	is_dead = false;
	start = get_current_time();
	while (true)
	{
		if (ph_is_dead(philo))
		{
			ph_dead(philo);
			break;
		}
		current = get_current_time();
		if (current >= start + time)
			break;
		usleep(200);
	}
}

void ph_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = DEATH;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
}

int	ph_is_dead(t_philo *philo)
{
	int				ret;
	unsigned long	current;
	
	pthread_mutex_lock(&philo->life);
	ret = false;
	current = get_current_time() - philo->init_time;
	if (current > philo->life_count)
		ret = true;
	pthread_mutex_unlock(&philo->life);
	return (ret);
}

void ph_print_state(t_philo *philo)
{
	t_monitor *m;

	m = philo->monitor;
	pthread_mutex_lock(&m->end);
	if (m->is_end_check == true)
	{
		m->is_end = true;
		pthread_mutex_unlock(&m->end);
		return ;
	}
	pthread_mutex_unlock(&m->end);

	pthread_mutex_lock(&m->end);
	if (m->is_end_check == false)
	{
		if (philo->status == DEATH)
		{
			m->is_end_check = true;
		}
		pthread_mutex_unlock(&m->end);

		pthread_mutex_lock(&m->speak);
		printf("%lu ms  ", get_current_time() - philo->init_time);
		printf("%d  ", philo->id + 1);
		if (philo->status == SLEEP)
			printf("%s\n", "is sleeping");
		else if (philo->status == EAT)
			printf("%s\n", "is eating");
		else if (philo->status == THINK)
			printf("%s\n", "is thinking");
		else if (philo->status == FORK)
			printf("%s\n", "has taken a fork");
		else if (philo->status == DEATH)
			printf("%s\n", "died");
		else
			printf("%s\n", "error!");
		pthread_mutex_unlock(&m->speak);
	} else
		pthread_mutex_unlock(&m->end);

}

int	ph_check_monitor(t_philo* philo)
{
	int	ret;
	
	pthread_mutex_lock(&philo->monitor->end);
	ret = false;
	if (philo->monitor->is_end)
		ret = true;
	pthread_mutex_unlock(&philo->monitor->end);
	return (ret);
}