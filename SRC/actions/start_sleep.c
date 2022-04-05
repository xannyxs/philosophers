/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:32:59 by xander        #+#    #+#                 */
/*   Updated: 2022/04/05 22:37:26 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>

void	start_sleep(t_philos *philos)
{
	printf("%4lld | %d is sleeping\n", \
		get_time() - philos->start_time, philos->philo_number);
	usleep(philos->input.time_sleep * 1000);
	philos->status = THINK;
}
