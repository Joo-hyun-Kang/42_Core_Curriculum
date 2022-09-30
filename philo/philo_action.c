/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:48 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 17:32:49 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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