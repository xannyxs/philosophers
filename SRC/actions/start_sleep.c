/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:32:59 by xander        #+#    #+#                 */
/*   Updated: 2022/04/11 18:44:57 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>

void	start_sleep(t_philos *philos)
{
	if (!pthread_mutex_lock(philos->vars->check_death_status))
		print_wrap(philos);
	usleep(philos->input.time_sleep * 1000);
	philos->status = THINK;
}
