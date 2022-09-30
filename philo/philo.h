/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:22:05 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 12:22:50 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#define NULL ((void *) 0)

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct monitor t_monitor;

enum e_ERROR {
	SYSTEM_CALL,
	ARGUMENT,
};

enum e_STATUS {
	THINK,
	SLEEP,
	EAT,
	FORK,
	DEATH,
	NONE,
};

typedef struct fork {
	pthread_mutex_t fork;
} t_fork;

typedef struct philo {
	int				id;
	int				philo_num;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	unsigned long	init_time;
	unsigned long	life_count;
	enum e_STATUS	status;
	pthread_t		thread;
	pthread_mutex_t death;
	t_fork			**forks;
	t_monitor		*monitor;
}	t_philo;

typedef struct monitor {
	int 			philo_num;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int				count_must_eat;
	bool			is_end;
	pthread_mutex_t speak;
	pthread_mutex_t end;
	t_philo			**philos;
}	t_monitor;

/* main.c */
bool ft_get_forks(t_fork ***out_forks, int fork_cnt);
bool ft_get_philos(t_monitor *monitor, t_fork **forks, int count);
void	ft_philo_check_finish(t_monitor *m);


/* philo.c */
bool 			ph_construct(t_philo **philo, int id, t_fork **forks, t_monitor *m);
void	*ph_activate_philo(void *arg);
void	ph_free(t_fork **philo);

bool ph_is_thinker(t_philo *philo);
void ph_wait(t_philo *philo);
void ph_think(t_philo *philo);
void ph_eat(t_philo *philo);
void ph_sleep(t_philo *philo);
void ph_spend(t_philo *philo, unsigned long time);
void ph_dead(t_philo *philo);
int	ph_is_dead(t_philo *philo);
void ph_print_state(t_philo *philo);

/* philo_utils.c */
int		ft_isdigit(int c);
int		ft_isspace(char ch);
int		ft_atoi(const char *str);
int		print_error(enum e_ERROR code);
unsigned long	get_current_time(void);

/* monitor.c */
bool mo_construct(t_monitor *monitor, int argc, char **argv);
void mo_set_philos(t_monitor *monitor, t_philo **philos);
bool mo_start_philo(t_monitor *monitor);

/* fork.c */
bool fk_construct(t_fork **out_fork);
void fk_free(t_fork **out_fork);

#endif