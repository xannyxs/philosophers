/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/12 20:36:42 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static void	start_something(t_philos *philos)
{
	if (philos->status == GRAB_LEFT)
		start_eat(philos);
	else if (philos->status == SLEEP)
		start_sleep(philos);
	else if (philos->status == THINK)
		start_think(philos);
}

static void	*start_routine(void *arg)
{
	t_philos	*philos;

	philos = arg;
	philos->last_time_eaten = 0;
	if (philos->philo_number % 2 == 0)
		u_better_sleep(philos, 80);
	while (true)
	{
		if (is_philo_dying(philos) || philos->input.philos <= 1 || \
			philos->vars->death_status)
		{
			philos->status = DEATH;
			if (!pthread_mutex_lock(philos->vars->protect_printf))
			{
				philos->vars->death_status = true;
				print_wrap(philos);
			}
			break ;
		}
		start_something(philos);
	}
	return (NULL);
}

static int	start_thread_create(t_philos *philos)
{
	int	i;
	int	err;

	i = 0;
	while (i < philos->input.philos)
	{
		err = pthread_create(&philos[i].vars->threads[i], NULL, \
			start_routine, &philos[i]);
		if (err != 0)
			return (1);
		i++;
	}
	return (0);
}

static int	init_thread_routine(t_philos *philos)
{
	int	i;
	int	err;

	i = 0;
	err = start_thread_create(philos);
	if (err != 0)
		return (1);
	while (i < philos->input.philos)
	{
		err = pthread_join(philos->vars->threads[i], NULL);
		if (err != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < philos->input.philos)
	{
		pthread_mutex_destroy(&philos->vars->forks[i]);
		i++;
	}
	pthread_mutex_destroy(philos->vars->protect_printf);
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
