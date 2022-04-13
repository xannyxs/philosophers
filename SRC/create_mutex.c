/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_mutex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 16:21:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/13 14:44:17 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>

int	setup_mutex(t_philos *philos)
{
	int	i;

	i = 0;
	philos->vars->forks = malloc(sizeof(pthread_mutex_t) \
		* philos->input.philos);
	if (!philos->vars->forks)
		return (error_complex_msg(5, philos));
	while (i < philos->input.philos)
	{
		if (pthread_mutex_init(&philos->vars->forks[i], NULL) != 0)
			return (error_complex_msg(6, philos));
		i++;
	}
	philos->vars->protect_printf = malloc(sizeof(pthread_mutex_t));
	if (!philos->vars->protect_printf)
		return (error_complex_msg(6, philos));
	if (pthread_mutex_init(philos->vars->protect_printf, NULL))
	{
		destroy_fork_mutex(philos);
		return (error_complex_msg(7, philos));
	}
	return (0);
}
