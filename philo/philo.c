/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:15:24 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 12:23:07 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool ph_construct(t_philo **philo, int id, t_fork **forks, t_monitor *m)
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
	(*philo)->forks = forks;
	(*philo)->status = NONE;
	(*philo)->monitor = m;
	ret = pthread_mutex_init(&(*philo)->death, NULL);
    if (ret == -1)
        return (false);
	return (true);
}

void ph_free(t_fork **philo)
{
    free(*philo);
}

void	*ph_activate_philo(void *philo)
{
	t_philo *p;

	p = (t_philo *)philo;
	if (ph_is_thinker(p))
		ph_wait(p);
	while (!p->monitor->is_end)
	{
		ph_eat(p);
		ph_sleep(p);
		ph_think(p);
	}
	return (NULL);
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
	if (philo->monitor->is_end)
		return ;
	philo->status = THINK;
	ph_print_state(philo);
}

void ph_eat(t_philo *philo)
{
	if (philo->monitor->is_end)
		return ;
	philo->status = EAT;
	philo->life_count = get_current_time();
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_eat);
}

void ph_sleep(t_philo *philo)
{
	if (philo->monitor->is_end)
		return ;
	philo->status = SLEEP;
	ph_print_state(philo);
	ph_spend(philo, philo->time_to_sleep);
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
		current = get_current_time();
		is_dead = ph_is_dead(philo);
		if (is_dead || current >= start + time)
			break;
		usleep(200);
	}
	if (is_dead)
		ph_dead(philo);
}

void ph_dead(t_philo *philo)
{
	philo->status = DEATH;
	pthread_mutex_lock(&philo->monitor->end);
	if (philo->monitor->is_end == false)
		philo->monitor->is_end = true;
	else
	{
		pthread_mutex_unlock(&philo->monitor->end);
		return ;
	}
	pthread_mutex_unlock(&philo->monitor->end);
	pthread_mutex_lock(&philo->monitor->speak);
	printf("%lu ms  ", get_current_time() - philo->init_time);
	printf("%d  %s\n", philo->id + 1, "died");
	pthread_mutex_unlock(&philo->monitor->speak);
}

int	ph_is_dead(t_philo *philo)
{
	int				ret;
	unsigned long	current;
	
	pthread_mutex_lock(&philo->death);
	ret = false;
	current = get_current_time();
	if (current - philo->life_count > (unsigned long)philo->time_to_die)
		ret = true;
	pthread_mutex_unlock(&philo->death);
	return (ret);
}

void ph_print_state(t_philo *philo)
{
	t_monitor	*m;

	if (philo->monitor->is_end)
		return ;
	m = philo->monitor;
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
	else
		printf("%s\n", "error!");
	pthread_mutex_unlock(&m->speak);
}