/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:46:51 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/13 16:23:20 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	destroy_fork_mutex(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->input.philos)
	{
		if (pthread_mutex_destroy(&philos->vars->forks[i]))
			return (ERROR);
		i++;
	}
	return (SUCCES);
}

int	destroy_all_mutex(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->input.philos)
	{
		if (pthread_mutex_destroy(&philos->vars->forks[i]))
			return (ERROR);
		i++;
	}
	if (pthread_mutex_destroy(philos->vars->protect_printf))
		return (ERROR);
	return (SUCCES);
}

int	error_msg(int error_num)
{
	if (error_num == 1)
		dprintf(STDERR_FILENO, "Need more arguments");
	else if (error_num == 2)
		dprintf(STDERR_FILENO, "You cannot use negative digtis");
	else if (error_num == 3)
		dprintf(STDERR_FILENO, "malloc: Out of memory");
	dprintf(STDERR_FILENO, "\n");
	return (ERROR);
}

int	error_complex_msg(int error_num, t_philos *philos)
{
	if (error_num == 4 || error_num == 5)
	{
		if (error_num == 5)
			free(philos->vars);
		free(philos);
		dprintf(STDERR_FILENO, "malloc: Out of memory");
	}
	else if (error_num == 6 || error_num == 7 || error_num == 8)
	{
		if (error_num == 8)
			free(philos->vars->threads);
		if (error_num != 6)
			free(philos->vars->protect_printf);
		free(philos->vars->forks);
		free(philos->vars);
		free(philos);
		if (error_num == 6 || error_num == 8)
			dprintf(STDERR_FILENO, "pthread mutex: somethings wrong...");
		else if (error_num == 7)
			dprintf(STDERR_FILENO, "malloc: Out of memory");
	}
	dprintf(STDERR_FILENO, "\n");
	return (ERROR);
}
