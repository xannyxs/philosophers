/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_mutex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 16:21:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/08 17:27:44 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int setup_mutex(t_philos *philos)
{
    int i;
    int err;

    i = 0;
    philos->forks = malloc(sizeof(pthread_mutex_t) * vars->input.philos);
    if (vars->forks == NULL)
    {
        free(vars->forks);
        exit(2);
    }
    err = pthread_mutex_init(vars->forks, NULL);
    if (err != 0)
    {
        pthread_mutex_destroy(vars->forks);
        exit(2);
    }
    return (0);
}