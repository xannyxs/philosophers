/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_mutex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 16:21:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/10 19:06:20 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	setup_mutex(t_philos *philos)
{
	int	i;
	int	err;

	i = 0;
	philos->vars->forks = malloc(sizeof(pthread_mutex_t) \
		* philos->input.philos);
	if (philos->vars->forks == NULL)
	{
		free(philos->vars->forks);
		exit(2);
	}
	err = pthread_mutex_init(philos->vars->forks, NULL);
	if (err != 0)
	{
		pthread_mutex_destroy(philos->vars->forks);
		exit(2);
	}
	return (0);
}
