/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 17:31:48 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/12 15:15:25 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	get_current_time(t_philos *philos)
{
	int	current_time;

	current_time = get_time() - philos->start_time;
	return (current_time);
}

unsigned long	get_time(void)
{
	unsigned long		time;
	struct timeval		timeval;

	gettimeofday(&timeval, NULL);
	time = (timeval.tv_sec * 1000) + (timeval.tv_usec / 1000);
	return (time);
}

void	u_better_sleep(unsigned long ms)
{
	unsigned long	starting_point;

	starting_point = get_time();
	while ((get_time() - starting_point) < ms)
		usleep(150);
}