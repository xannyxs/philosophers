/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:27:51 by xander        #+#    #+#                 */
/*   Updated: 2022/04/05 22:47:01 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>

void	start_think(t_philos *philos)
{
	printf("%4lld | %d is thinking\n", \
		get_time() - philos->start_time, philos->philo_number);
	philos->status = EAT;
}
