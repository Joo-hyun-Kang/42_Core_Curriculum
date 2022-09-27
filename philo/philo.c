#include "philo.h"



int	main(int argc, char **argv)
{
	t_monitor	monitor;
	t_forks		forks;
	int			i;

	if (construct_monitor(&monitor, argc, argv) == false)
		return print_error(ARGUMENT);

	forks.forks = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t) * monitor.philo_num));
	monitor.philos = (t_philo *)malloc((sizeof(t_philo) * monitor.philo_num));
	if (forks.forks == NULL || monitor.philos == NULL)
		return print_error(MALLOC);

	forks.num = 0;
	pthread_mutex_init(&(forks.test), NULL);
	i = 0;
	while (i < monitor.philo_num)
	{
		pthread_mutex_init(&(forks.forks[i]), NULL);
		monitor.philos[i].idx = i;
		monitor.philos[i].forks = &forks;
		i++;
	}
	
	//monitor create
	i = 0;
	while (i < monitor.philo_num)
	{
		pthread_create(&monitor.philos[i].thread, NULL, &ft_activate_philo, &monitor.philos[i]);
		i++;
	}
	
	//monitor watching
	i = 0;
	while (i < monitor.philo_num)
	{
		pthread_join(monitor.philos[i].thread, NULL);
		i++;
	}


	//free statement
	// free(monitor.philos);
	// free(forks.forks);
	//mutex destroy(monitor.forks)

	//쓰레드 종료?

	return 0;

}

//philo
void	*ft_activate_philo(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->forks->test);
	printf("hi! i'm %p the number is %d\n", &philo->idx, philo->forks->num);
	philo->forks->num++;
	pthread_mutex_unlock(&philo->forks->test);

	return NULL;
}