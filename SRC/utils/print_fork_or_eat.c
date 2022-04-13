/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_fork_or_eat.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 20:34:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/13 18:31:02 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h> /* printf */

void	print_eat(t_philos *philos)
{
	printf("%4d | %d is eating\n", \
		get_current_time(philos), philos->philo_number);
}

void	print_right_fork(t_philos *philos)
{
	printf("%4d | %d has taken a right fork\n", \
		get_current_time(philos), philos->philo_number);
}

void	print_left_fork(t_philos *philos)
{
	printf("%4d | %d has taken a left fork\n", \
		get_current_time(philos), philos->philo_number);
}
