/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_sleep.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 22:32:59 by xander        #+#    #+#                 */
/*   Updated: 2022/04/13 18:31:57 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sleep(t_philos *philos)
{
	if (!pthread_mutex_lock(philos->vars->protect_printf))
		print_wrap(philos);
	u_better_sleep(philos, philos->input.time_sleep);
	philos->status = THINK;
}
