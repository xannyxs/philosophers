/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:27:51 by xander        #+#    #+#                 */
/*   Updated: 2022/04/09 18:42:28 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>

void	start_think(t_philos *philos)
{
	if (philos->vars->death_status == true)
		return ;
	printf("%4d | %d is thinking\n", \
		get_current_time(philos), philos->philo_number);
	philos->status = EAT;
}
