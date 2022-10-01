/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:54 by jokang            #+#    #+#             */
/*   Updated: 2022/10/01 23:03:29 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	up_fork_alone(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = FORK;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	while (!ph_is_dead(philo))
	{
	}
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = DEATH;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	pthread_mutex_unlock(philo->left);
}

bool	try_up_fork(t_philo *philo)
{
	usleep(300);
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(&philo->status_mtx);
	if (philo->status == DEATH)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(&philo->status_mtx);
		return (false);
	}
	philo->status = FORK;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = FORK;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	return (true);
}
