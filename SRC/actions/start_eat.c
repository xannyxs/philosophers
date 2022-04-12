/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:31:45 by xander        #+#    #+#                 */
/*   Updated: 2022/04/12 16:31:21 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdio.h>

void	start_eat(t_philos *philos)
{
	pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	philos->status = GRAB_RIGHT;
	if (is_philo_dying(philos) == true)
	{
		pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
		return ;
	}
	pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	if (is_philo_dying(philos) == true)
	{
		pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
		pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
		return ;
	}
	philos->status = EAT;
	philos->last_time_eaten = get_current_time(philos);
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	u_better_sleep(philos, philos->input.time_eat);
	philos->status = SLEEP;
	pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
}
