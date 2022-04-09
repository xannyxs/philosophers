/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:32:59 by xander        #+#    #+#                 */
/*   Updated: 2022/04/09 18:42:22 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>

void	start_sleep(t_philos *philos)
{
	if (philos->vars->death_status == true)
		return ;
	printf("%4d | %d is sleeping\n", \
		get_current_time(philos), philos->philo_number);
	usleep(philos->input.time_sleep * 1000);
	philos->status = THINK;
}
