/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:22:05 by jokang            #+#    #+#             */
/*   Updated: 2022/09/27 23:01:24 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define __NULLABLE

enum e_ERROR {
	MALLOC,
	ARGUMENT,
};

typedef struct forks {
	pthread_mutex_t *forks;
	pthread_mutex_t test;
	int				num;
} t_forks;

typedef struct philo {
	int				idx;
	pthread_t		thread;	
	t_forks			*forks;
}	t_philo;

typedef struct monitor {
	int 			philo_num;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				count_must_eat;
	t_philo			*philos;
}	t_monitor;

/* philo.c */

void	*ft_activate_philo(void *arg);


/* philo_utils.c */
int		ft_isdigit(int c);
int		ft_isspace(char ch);
int		ft_atoi(const char *str);
int		print_error(enum e_ERROR code);

/* monitor.c */
bool construct_monitor(t_monitor *monitor, int argc, char **argv);
