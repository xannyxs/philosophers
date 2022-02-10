/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:31:45 by xander        #+#    #+#                 */
/*   Updated: 2022/02/10 22:53:55 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_eat(t_philos *philos)
{
	printf("%4ld | %d has taken a fork\n", \
		philos->end_tv.tv_sec, philos->philo_number);
	pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
	printf("%4ld | %d has taken a fork\n", \
		philos->end_tv.tv_sec, philos->philo_number);
	pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
	printf("%4ld | %d is eating\n", \
		philos->end_tv.tv_sec, philos->philo_number);
	philos->status = SLEEP;
	usleep(philos->input.time_eat * 1000);
	pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
}
