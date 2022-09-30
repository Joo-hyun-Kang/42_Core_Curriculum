/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:51 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 17:32:52 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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