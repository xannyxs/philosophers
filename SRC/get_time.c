/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 17:31:48 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/16 19:28:30 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time(void)
{
	int					err;
	unsigned long long	time;
	struct timeval		timeval;

	err = gettimeofday(&timeval, NULL);
	if (err != 0)
		exit(1);
	time = (timeval.tv_sec * 1000) + (timeval.tv_usec / 1000);
	return (time);
}
