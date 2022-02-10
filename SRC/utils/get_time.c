/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 17:31:48 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/10 18:57:00 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

struct timeval	get_time(t_philos *philos)
{
	int				err;
	struct timeval	result_tv;

	err = gettimeofday(&philos->end_tv, NULL);
	if (err != 0)
		exit(1);
	result_tv.tv_sec = (philos->end_tv.tv_sec - philos->start_tv.tv_sec) * 100;
	return (result_tv);
}
