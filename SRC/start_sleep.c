/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:32:59 by xander        #+#    #+#                 */
/*   Updated: 2022/02/16 19:14:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sleep(t_philos *philos)
{
	printf("%4lld | %d is sleeping\n", \
		get_time() - philos->start_time, philos->philo_number);
	usleep(philos->input.time_sleep * 1000);
	philos->status = THINK;
}
