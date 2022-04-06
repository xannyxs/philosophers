/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:31:45 by xander        #+#    #+#                 */
/*   Updated: 2022/04/06 20:32:12 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdio.h>

void	start_eat(t_philos *philos)
{
	pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
	printf("%4d | %d has taken a left fork\n", \
		get_current_time(philos), philos->philo_number);
	pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
	printf("%4d | %d has taken a right fork\n", \
		get_current_time(philos), philos->philo_number);
	philos->status = SLEEP;
	printf("%4d | %d is eating\n", \
		get_current_time(philos), philos->philo_number);
	philos->last_time_eaten = get_current_time(philos);
	usleep(philos->input.time_eat * 1000);
	pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
}
