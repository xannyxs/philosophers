/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/09 17:56:49 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include <stdio.h>

static bool	is_philo_dying(t_philos *philos)
{
	if (get_current_time(philos) - philos->last_time_eaten >= \
		(unsigned long long) philos->input.time_die)
		return (true);
	return (false);
}

static void	*start_routine(void *arg)
{
	t_philos	*philos;

	philos = arg;
	philos->last_time_eaten = 0;
	while (true)
	{
		if (is_philo_dying(philos) == true)
		{
			printf("philo %d has died\n", philos->philo_number);
			exit(1);
		}
		if (philos->status == EAT)
			start_eat(philos);
		else if (philos->status == SLEEP)
			start_sleep(philos);
		else if (philos->status == THINK)
			start_think(philos);
	}
	return (NULL);
}

static int	init_thread_routine(t_philos *philos)
{
	int	i;
	int	err;

	i = 0;
	while (i < philos->input.philos)
	{
		err = pthread_create(philos[i].vars->threads, NULL, \
			start_routine, &philos[i]);
		if (err != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < philos->input.philos)
	{
		err = pthread_join(*philos[i].vars->threads, NULL);
		if (err != 0)
			return (1);
		i++;
	}
	return (0);
}

int	start_thread(t_philos *philos)
{
	int	err;

	philos->vars->threads = malloc(sizeof(pthread_t) * philos->input.philos);
	if (philos->vars->threads == NULL)
	{
		free(philos->vars->threads);
		return (1);
	}
	err = init_thread_routine(philos);
	if (err != 0)
		return (1);
	return (0);
}
