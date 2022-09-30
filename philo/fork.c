/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokang <autoba9687@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:33 by jokang            #+#    #+#             */
/*   Updated: 2022/09/30 18:24:23 by jokang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}