/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_mutex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 16:21:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/12 14:02:19 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>

static int	setup_status_mutex(t_philos *philos)
{
	int	i;
	int	err;

	i = 0;
	philos->vars->protect_printf = malloc(sizeof(pthread_mutex_t));
	if (philos->vars->protect_printf == NULL)
	{
		free(philos->vars->protect_printf);
		return (1);
	}
	err = pthread_mutex_init(philos->vars->protect_printf, NULL);
	if (err != 0)
		return (1);
	return (0);
}

int	setup_mutex(t_philos *philos)
{
	int	i;
	int	err;

	i = 0;
	philos->vars->forks = malloc(sizeof(pthread_mutex_t) \
		* philos->input.philos);
	if (philos->vars->forks == NULL)
	{
		free(philos->vars->forks);
		return (1);
	}
	while (i < philos->input.philos)
	{
		err = pthread_mutex_init(&philos->vars->forks[i], NULL);
		if (err != 0)
			return (1);
		i++;
	}
	if (setup_status_mutex(philos) != 0)
		return (1);
	return (0);
}
