#include "philo.h"

void fk_free(pthread_mutex_t *out_fork, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        pthread_mutex_destroy(&out_fork[i]);
        i++;
    }
    free(out_fork);
}