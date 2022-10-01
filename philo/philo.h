/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <jokang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 22:22:05 by jokang            #+#    #+#             */
/*   Updated: 2022/10/01 23:02:23 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define NUL ((void *) 0)

typedef struct monitor	t_monitor;

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

typedef struct philo {
	int				id;
	int				philo_num;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				count_must_eat;
	int				eat_count;
	unsigned long	init_time;
	unsigned long	life_count;
	enum e_STATUS	status;
	pthread_t		thread;
	pthread_mutex_t	life;
	pthread_mutex_t	status_mtx;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	t_monitor		*monitor;
}	t_philo;

typedef struct monitor {
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_must_eat;
	int				finish_philos;
	int				waiter_offset;
	bool			is_end_check;
	bool			is_end;
	pthread_mutex_t	must;
	pthread_mutex_t	watier;
	pthread_mutex_t	speak;
	pthread_mutex_t	end;
	pthread_mutex_t	*forks;
	t_philo			**philos;
}	t_monitor;

/* main.c */
bool			ft_get_forks(t_monitor *m);
bool			ft_get_philos(t_monitor *monitor, int count);
void			ft_philo_check_finish(t_monitor *m);
void			free_resource(t_monitor *m);

/* philo.c */
bool			ph_construct(t_philo **philo, int id, t_monitor *m);
void			*ph_activate_philo(void *arg);
bool			ph_is_waiter(t_philo *philo);
bool			ph_is_thinker(t_philo *philo);
bool			ph_count_must_eat(t_philo *p);

/* philo_action.c */
void			ph_wait(t_philo *philo);
void			ph_think(t_philo *philo);
void			ph_eat(t_philo *philo);
void			ph_sleep(t_philo *philo);
void			ph_spend(t_philo *philo, unsigned long time);

/* philo_fork.c */
void			up_fork_alone(t_philo *philo);
bool			try_up_fork(t_philo *philo);

/* philo_death.c */
int				ph_check_monitor(t_philo *philo);
void			ph_dead(t_philo *philo);
int				ph_is_dead(t_philo *philo);
void			ph_print_state(t_philo *philo);
void			ph_print_helper(t_monitor *m, t_philo *philo);

/* utils.c */
int				ft_isdigit(int c);
int				ft_isspace(char ch);
int				ft_atoi(const char *str);
int				print_error(enum e_ERROR code);
unsigned long	get_current_time(void);

/* monitor.c */
bool			mo_construct(t_monitor *monitor, int argc, char **argv);
bool			mo_construct_helper(t_monitor *monitor);
void			mo_set_philos(t_monitor *monitor, t_philo **philos);
bool			mo_start_philo(t_monitor *monitor);
void			mo_check_philos(t_monitor *m);

/* fork.c */
void			fk_free(pthread_mutex_t *out_fork, int count);

#endif