/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_wrap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 18:28:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/11 18:53:58 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>

static void	print_eat_and_forks(t_philos *philos)
{
	pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
	printf("%4d | %d has taken a left fork\n", \
		get_current_time(philos), philos->philo_number);
	pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
	printf("%4d | %d has taken a right fork\n", \
		get_current_time(philos), philos->philo_number);
	printf("%4d | %d is eating\n", \
		get_current_time(philos), philos->philo_number);
}

static void	print_think(t_philos *philos)
{
	printf("%4d | %d is thinking\n", \
		get_current_time(philos), philos->philo_number);
}

static void	print_sleep(t_philos *philos)
{
	printf("%4d | %d is sleeping\n", \
		get_current_time(philos), philos->philo_number);
}

static void	print_death(t_philos *philos)
{
	printf("%4d | philo %d has died\n", get_current_time(philos),
		philos->philo_number);
	philos->vars->first_death = false;
}

void	print_wrap(t_philos *philos)
{
	if (philos->status == DEATH && philos->vars->first_death == true)
		print_death(philos);
	else if (philos->vars->death_status == false)
	{
		if (philos->status == EAT)
			print_eat_and_forks(philos);
		else if (philos->status == THINK)
			print_think(philos);
		else if (philos->status == SLEEP)
			print_sleep(philos);
	}
	pthread_mutex_unlock(philos->vars->check_death_status);
}
