#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

enum	e_STATE {
	EATING,
	THINKING,
	HUNGRY
};

typedef struct thread_info {
	 philo_num;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int	count_must_eat;
}	t_info;

typedef struct philo {
	t_info			info;
	pthread_t		*philsophers;
	pthread_mutex_t *forks;
	pthread_mutex_t	state_mutx;
	enum e_STATE	*states;
	bool			*authority;
	int				cur;
}	t_philo;

/* philo.c */
void	*ft_activate_philo(void *philo);
void	ft_create_philo(t_philo philo, int idx);

/* philo_utils.c */
int		ft_atoi(const char *str);
