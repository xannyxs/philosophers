/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/06 20:30:59 by xvoorvaa      ########   odam.nl         */
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
	if ((philos->status % 2) == true)
		usleep(50);
	while (true)
	{
		// printf("%llu\n", (get_current_time() - philos->last_time_eaten);
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

void	start_thread(t_philos *philos)
{
	int	i;

	i = 0;
	philos->vars->threads = malloc(sizeof(pthread_t) * philos->input.philos);
	if (philos->vars->threads == NULL)
		exit(-1);
	while (i < philos->input.philos)
	{
		pthread_create(philos[i].vars->threads, NULL, \
			start_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < philos->input.philos)
	{
		pthread_join(*philos[i].vars->threads, NULL);
		i++;
	}
}
