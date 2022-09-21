#include "philo.h"

bool construct_info(t_info *info, int argc, char **argv)
{
	int arguments[argc];
	
	if (argc < 5 || argc > 6)
		return (false);
	int i = 1;
	while (i < argc)
	{
		arguments[i] = ft_atoi(argv[i]);
		if (arguments[i] <= 0) 
			return (false);
		i++;
	}
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->count_must_eat = ft_atoi(argv[5]);
	else
		info->count_must_eat = -1;
	return (true);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	int			i;

	if (construct_info(&philo.info, argc, argv) == false)
	{
		printf("%s\n", "illegal argument");
		return (false);
	}

	philo.forks = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t) * philo.info.philo_num));
	philo.states = (enum e_STATE *)malloc((sizeof(enum e_STATE) * philo.info.philo_num));
	philo.authority = (bool *)malloc((sizeof(bool) * philo.info.philo_num));
	pthread_mutex_init(&philo.state_mutx, NULL);
	
	while (i < philo.info.philo_num)
	{
		pthread_mutex_init(&philo.forks[i], NULL);
		philo.states[i] = HUNGRY;
		philo.authority[i] = false;
		i++;
	}

	philo.philsophers = (pthread_t *)malloc((sizeof(pthread_t) * philo.info.philo_num));
	
	i = 0;
	while (i < philo.info.philo_num)
	{
		ft_create_philo(&philo, i);
		i++;
	}
	
	i = 0;
	while (i < philo.info.philo_num)
	{
		pthread_join(philo.philsophers[i], NULL);
		i++;
	}

	//free(arg);'
	//ft_destory_mutex -> forkes, state_mutx
	//ft_free_philo
	return 0;

}

void	ft_create_philo(t_philo *philo, int idx)
{
	philo->cur = idx;
	printf("cur is %d\n", philo->cur);
	pthread_create(&(philo->philsophers[idx]), NULL, &ft_activate_philo, philo);
}

void	*ft_activate_philo(void *philo)
{
	// int num = philo->cur;
	// printf("", 0);
	// printf("hi! i'm %d\n", *num);


	t_philo *ph;
	ph = (t_philo *)philo;
	printf("hi! i'm %d\n", ph->cur);
	
	
	// int		i;

	// i = ph->cur;
	
	// pick up
	// pthread_mutex_lock(&(ph->state_mutx));
	
	// ph->states[i] = HUNGRY;
	// if (ph->states[(i + 4) % 5] != EATING && \
	// ph->states[i] == HUNGRY && \
	// ph->states[(i + 1) % 5] != EATING)
	// {
	// 	ph->states[i] = EATING;
	// 	ph->authority[i] = true;
	// }
	// pthread_mutex_unlock(&(ph->state_mutx));
	return NULL;
}