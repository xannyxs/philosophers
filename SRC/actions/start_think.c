/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_think.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:27:51 by xander        #+#    #+#                 */
/*   Updated: 2022/04/13 18:32:32 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* GRAB_LEFT will eventually change to EAT */
void	start_think(t_philos *philos)
{
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	philos->status = GRAB_LEFT;
}
