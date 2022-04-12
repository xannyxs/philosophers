/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_eat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:31:45 by xander        #+#    #+#                 */
/*   Updated: 2022/04/12 20:38:01 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdio.h>

static int	grab_fork(t_philos *philos)
{
	pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	philos->status = GRAB_RIGHT;
	if (is_philo_dying(philos) == true)
	{
		pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
		return (1);
	}
	pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	if (is_philo_dying(philos) == true)
	{
		pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
		pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
		return (1);
	}
	return (0);
}

void	start_eat(t_philos *philos)
{
	if (grab_fork(philos) != 0)
		return ;
	philos->status = EAT;
	philos->last_time_eaten = get_current_time(philos);
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	u_better_sleep(philos, philos->input.time_eat);
	philos->status = SLEEP;
	pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
}
