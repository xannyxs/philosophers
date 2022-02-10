/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:32:59 by xander        #+#    #+#                 */
/*   Updated: 2022/02/10 22:54:02 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_sleep(t_philos *philos)
{
	printf("%4ld | %d is sleeping\n", \
		philos->end_tv.tv_sec, philos->philo_number);
	usleep(philos->input.time_sleep * 1000);
	philos->status = THINK;
}
