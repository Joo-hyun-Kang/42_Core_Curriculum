#include "philo.h"

int ft_try_init_info(t_info *info, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (false);

	// 예외 케이스 
	// 1. int 이상 범위일 때 예외처리 해주기
	// 2. 숫자가 아닐 때
	// 3. 음수 일 때
	// 매직 넘버 날리기

	//argv[1]이 4비트 표현 범위보다 클 때  생기는 문제
	//철학자가 1명이면 예외처리? --> 일단 나오고 죽는게 맞음
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

	//매개변수 가지는 거 초기화 해주기
	if (ft_try_init_info(&philo.info, argc, argv) == false)
	{
		printf("%s\n", "illegal argument");
		return (false);
	}

	//철학자 만들고 그만큼 포크를 만듬
	int i = 0;
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
		ft_create_philo(philo, i);
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

}

void	ft_create_philo(t_philo philo, int idx)
{
	philo.cur = idx;
	//int *num = (int *)malloc(sizeof(int));
	//*num = idx;
	printf("cur is %d\n", philo.cur);
	pthread_create(&(philo.philsophers[idx]), NULL, &ft_activate_philo, &philo);
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