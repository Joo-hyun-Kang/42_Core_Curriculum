#include "philo.h"

bool fk_construct(t_fork **out_fork)
{
    int res;
    
    (*out_fork) = (t_fork *)malloc((sizeof(t_fork)));
    if (*out_fork == NULL)
        return (false);
    res = pthread_mutex_init(&(*out_fork)->fork, NULL);
    if (res == -1)
        return (false);
    return (true);
}

void fk_free(t_fork **out_fork)
{
    pthread_mutex_destroy(&(*out_fork)->fork);
    free(*out_fork);
}