/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:54 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 21:25:11 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	up_fork_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
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
	pthread_mutex_unlock(&philo->left);
}

void	down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left);
	pthread_mutex_unlock(&philo->right);
	philo->eat_count += 1;
}

void	up_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = FORK;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
	pthread_mutex_lock(&philo->right);
	pthread_mutex_lock(&philo->status_mtx);
	philo->status = FORK;
	pthread_mutex_unlock(&philo->status_mtx);
	ph_print_state(philo);
}
