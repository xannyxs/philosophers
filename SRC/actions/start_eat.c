/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:31:45 by xander        #+#    #+#                 */
/*   Updated: 2022/04/11 18:50:07 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdio.h>

void	start_eat(t_philos *philos)
{
	if (!pthread_mutex_lock(philos->vars->check_death_status))
		print_wrap(philos);
	philos->last_time_eaten = get_current_time(philos);
	usleep(philos->input.time_eat * 1000);
	philos->status = SLEEP;
	pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
}
