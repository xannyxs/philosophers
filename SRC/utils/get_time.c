/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 17:31:48 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/09 17:48:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	get_time(t_philos *philos)
{
	int	err;

	err = gettimeofday(&philos->tv, NULL);
	if (err != 0)
		exit(1);
	philos->tv.tv_usec = philos->tv.tv_usec - philos->start_tv.tv_usec;
	return (philos->tv.tv_usec);
}