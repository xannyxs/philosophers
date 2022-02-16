/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:27:51 by xander        #+#    #+#                 */
/*   Updated: 2022/02/16 19:14:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_think(t_philos *philos)
{
	printf("%4lld | %d is thinking\n", \
		get_time() - philos->start_time, philos->philo_number);
	usleep(1000);
	philos->status = EAT;
}
