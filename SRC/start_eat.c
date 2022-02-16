/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:31:45 by xander        #+#    #+#                 */
/*   Updated: 2022/02/16 19:14:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eat(t_philos *philos)
{
	printf("%4lld | %d has taken a fork\n", \
		get_time() - philos->start_time, philos->philo_number);
	pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
	printf("%4lld | %d has taken a fork\n", \
		get_time() - philos->start_time, philos->philo_number);
	pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
	printf("%4lld | %d is eating\n", \
		get_time() - philos->start_time, philos->philo_number);
	philos->status = SLEEP;
	usleep(philos->input.time_eat * 1000);
	pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
}
