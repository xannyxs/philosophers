/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:27:51 by xander        #+#    #+#                 */
/*   Updated: 2022/02/10 22:53:44 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_think(t_philos *philos)
{
	printf("%4ld | %d is thinking\n", \
		philos->end_tv.tv_sec, philos->philo_number);
	usleep(100);
	philos->status = EAT;
}
