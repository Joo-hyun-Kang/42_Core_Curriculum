/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:18:06 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 18:23:57 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool ft_get_forks(t_monitor *m)
{
    int i;
    int ret;

    m->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * m->philo_num);
    if (m->forks == NULL)
        return (false);
    i = 0;
    while (i < m->philo_num) 
    {
        ret = pthread_mutex_init(&m->forks[i], NULL);
        if (ret == -1)
            return (false);
        i++;
    }
    return (true);
}

bool ft_get_philos(t_monitor *monitor, int count)
{
    t_philo         **philos;
    
    int             i;

    philos = (t_philo **)malloc(sizeof(t_philo *) * count);
    if (philos == NULL)
        return (false);
    i = 0;
    while (i < count) 
    {
        if (ph_construct(&philos[i], i, monitor) == false)
            return (false);
        i++;
    }
    mo_set_philos(monitor, philos);
    return (true);
}

int	main(int argc, char **argv)
{
	t_monitor	monitor;
    int         ret;
    int         i;

	//모니터를 생성한다
	if (mo_construct(&monitor, argc, argv) == false)
		return print_error(ARGUMENT);

    //포크 배열을 생성한다
	ret = ft_get_forks(&monitor);
    if (ret == false)
        return print_error(SYSTEM_CALL);

    //철학자들의 배열을 생성하고 모니터에 등록한다
    ret = ft_get_philos(&monitor, monitor.philo_num);
    if (ret == false)
        return print_error(SYSTEM_CALL);

	//monitor create
    if (mo_start_philo(&monitor) == false)
        return print_error(SYSTEM_CALL);

	//monitor watching
    mo_check_philos(&monitor);

	i = 0;
	while (i < monitor.philo_num)
	{
        pthread_join(monitor.philos[i]->thread, NULL);
        i++;
	}

	//free statement
    free_resource(&monitor);

    while (1)
    {
    }

	return 0;

}

void    free_resource(t_monitor *m)
{
    int i;
    
    fk_free(m->forks, m->philo_num);
    free(m->forks);
    m->forks = NULL;
    pthread_mutex_destroy(&m->must);
	pthread_mutex_destroy(&m->watier);
	pthread_mutex_destroy(&m->speak);
	pthread_mutex_destroy(&m->end);
    i = 0;
    while (i < m->philo_num)
    {
        pthread_mutex_destroy(&m->philos[i]->life);
	    pthread_mutex_destroy(&m->philos[i]->status_mtx);
        free(m->philos[i]);
        m->philos[i] = NULL;
        i++;
    }
    free(m->philos);
    m->philos = NULL;
}
