/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:18:06 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 12:22:24 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool ft_get_forks(t_fork ***out_forks, int fork_cnt)
{
    int i;

    (*out_forks) = (t_fork **)malloc(sizeof(t_fork *) * fork_cnt);
    if (*out_forks == NULL)
        return (false);
    i = 0;
    while (i < fork_cnt) 
    {
        if (fk_construct(&(*out_forks)[i]) == false)
            return (false);
        i++;
    }
    return (true);
}

bool ft_get_philos(t_monitor *monitor, t_fork **forks, int count)
{
    t_philo         **philos;
    unsigned long   time;
    int             i;

    philos = (t_philo **)malloc(sizeof(t_philo *) * count);
    if (philos == NULL)
        return (false);
    i = 0;
    time = get_current_time();
    while (i < count) 
    {
        if (ph_construct(&philos[i], i, forks, monitor) == false)
            return (false);
        philos[i]->init_time = time;
        i++;
    }
    mo_set_philos(monitor, philos);
    return (true);
}

int	main(int argc, char **argv)
{
	t_monitor	monitor;
	t_fork		**forks;
    int         ret;
    int         i;

	//모니터를 생성한다
	if (mo_construct(&monitor, argc, argv) == false)
		return print_error(ARGUMENT);

    //포크 배열을 생성한다
	ret = ft_get_forks(&forks, monitor.philo_num);
    if (ret == false)
        return print_error(SYSTEM_CALL);

    //철학자들의 배열을 생성하고 모니터에 등록한다
    ret = ft_get_philos(&monitor, forks, monitor.philo_num);
    if (ret == false)
        return print_error(SYSTEM_CALL);

	//monitor create
    if (mo_start_philo(&monitor) == false)
        return print_error(SYSTEM_CALL);

	//monitor watching
    ft_philo_check_finish(&monitor);

	i = 0;
	while (i < monitor.philo_num)
	{
        pthread_join(monitor.philos[i]->thread, NULL);
		i++;
	}


	//free statement
	//forks 배열 내부 fork들과 그 안에 뮤텍스
    //forks 배열
    //philo
    //philos 배열
    //moniotr에서 philos speak end
    //philo 에서 death

	return 0;

}

void	ft_philo_check_finish(t_monitor *m)
{
	int             i;

	while (!m->is_end)
	{
		// if ((arg->eat_times != 0) && (arg->philo_num == arg->finished_eat))
		// {
		// 	arg->finish = 1;
		// 	break ;
		// }
		i = 0;
		while (i < m->philo_num)
		{
            ph_is_dead(m->philos[i]);
			i++;
		}
	}
}