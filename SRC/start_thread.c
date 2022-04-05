/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/05 22:48:51 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void	*start(void *arg)
{
	t_philos	*philos;

	philos = arg;
	if ((philos->status % 2) == true)
		usleep(1000);
	while (true)
	{
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
		pthread_create(philos[i].vars->threads, NULL, start, &philos[i]);
		i++;
	}
	i = 0;
	while (i < philos->input.philos)
	{
		pthread_join(*philos[i].vars->threads, NULL);
		i++;
	}
}
