/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/13 16:12:35 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static int	start_something(t_philos *philos)
{
	if (philos->status == GRAB_LEFT)
	{
		if (philos->input.amount_eat > 0 && philos->input.amount_eat != -1)
			philos->input.amount_eat--;
		else if (philos->input.amount_eat == 0)
			return (-1);
		start_eat(philos);
	}
	else if (philos->status == SLEEP)
		start_sleep(philos);
	else if (philos->status == THINK)
		start_think(philos);
	return (0);
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
		if (!pthread_mutex_lock(philos->vars->protect_printf))
		{
			if (is_philo_dying(philos) || philos->input.philos <= 1 || \
				philos->vars->death_status)
			{
				philos->status = DEATH;
				philos->vars->death_status = true;
				print_wrap(philos);
				break ;
			}
			pthread_mutex_unlock(philos->vars->protect_printf);
		}
		if (start_something(philos))
			break ;
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
		{
			destroy_all_mutex(philos);
			return (error_complex_msg(8, philos));
		}
		i++;
	}
	return (SUCCES);
}

static int	init_thread_routine(t_philos *philos)
{
	int	i;

	i = 0;
	if (start_thread_create(philos))
		return (ERROR);
	while (i < philos->input.philos)
	{
		if (pthread_join(philos->vars->threads[i], NULL))
		{	
			destroy_all_mutex(philos);
			return (error_complex_msg(8, philos));
		}
		i++;
	}
	if (destroy_all_mutex(philos))
		return (error_complex_msg(8, philos));
	return (SUCCES);
}

int	start_thread(t_philos *philos)
{
	philos->vars->threads = malloc(sizeof(pthread_t) * philos->input.philos);
	if (!philos->vars->threads)
	{
		destroy_all_mutex(philos);
		return (error_complex_msg(7, philos));
	}
	if (init_thread_routine(philos))
		return (ERROR);
	return (SUCCES);
}
