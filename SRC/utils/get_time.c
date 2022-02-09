/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 17:31:48 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/09 19:34:46 by xvoorvaa      ########   odam.nl         */
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
	// printf("TIME: %ld = %ld - %ld\n", result_tv.tv_sec, philos->start_tv.tv_sec, philos->end_tv.tv_sec);
	return (result_tv);
}
