/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_mutex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:19:03 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/03 20:35:19 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_mutex(t_vars *vars)
{
	int	i;
	int	err;

	i = 0;
	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->input.philos);
	if (vars->forks == NULL)
	{
		free(vars->forks);
		exit (-1);
	}
	while (i < vars->input.philos)
	{
		err = pthread_mutex_init(&vars->forks[i], NULL);
		if (err != 0)
		{
			pthread_mutex_destroy(vars->forks);
			exit (err);
		}
		i++;
	}
}
