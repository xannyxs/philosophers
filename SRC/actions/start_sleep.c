/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:32:59 by xander        #+#    #+#                 */
/*   Updated: 2022/04/06 20:42:55 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>

void	start_sleep(t_philos *philos)
{
	printf("%4d | %d is sleeping\n", \
		get_current_time(philos), philos->philo_number);
	usleep(philos->input.time_sleep * 1000);
	philos->status = THINK;
}
