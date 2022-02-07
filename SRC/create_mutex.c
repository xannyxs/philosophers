/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_mutex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 16:21:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/07 16:36:16 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int setup_mutex(t_vars *vars)
{
    vars->forks = malloc(sizeof(pthread_mutex_t) * vars->input.philos);
    if (vars->forks == NULL)
    {
        free(vars->forks);
        exit(2);
    }
    return (0);
}