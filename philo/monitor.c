#include "philo.h"

bool construct_monitor(t_monitor *monitor, int argc, char **argv)
{
	int arguments[5];
	
	if (argc < 5 || argc > 6)
		return (false);
	int idx = 1;
	while (idx < argc)
	{
		arguments[idx - 1] = ft_atoi(argv[idx]);
		if (arguments[idx - 1] <= 0) 
			return (false);
		idx++;
	}
	monitor->philo_num = arguments[0];
	monitor->time_to_die = arguments[1];
	monitor->time_to_eat = arguments[2];
	monitor->time_to_sleep = arguments[3];
	if (argc == 6)
		monitor->count_must_eat = arguments[4];
	else
		monitor->count_must_eat = -1;
	return (true);
}