/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_philo_dying.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 20:33:10 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/12 20:33:31 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_philo_dying(t_philos *philos)
{
	if (get_current_time(philos) - philos->last_time_eaten >= \
		(unsigned long) philos->input.time_die)
		return (true);
	return (false);
}
