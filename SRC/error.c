/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:46:51 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/13 18:29:19 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h> /* write */
#include <stdlib.h> /* free */

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
		write(STDERR_FILENO, "Need more arguments", 20);
	else if (error_num == 2)
		write(STDERR_FILENO, "You cannot use negative digtis", 31);
	else if (error_num == 3)
		write(STDERR_FILENO, "malloc: Out of memory", 22);
	write(STDERR_FILENO, "\n", 1);
	return (ERROR);
}

int	error_complex_msg(int error_num, t_philos *philos)
{
	if (error_num == 4 || error_num == 5)
	{
		if (error_num == 5)
			free(philos->vars);
		free(philos);
		write(STDERR_FILENO, "malloc: Out of memory", 22);
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
			write(STDERR_FILENO, "pthread mutex: something is wrong...", 37);
		else if (error_num == 7)
			write(STDERR_FILENO, "malloc: Out of memory", 22);
	}
	write(STDERR_FILENO, "\n", 1);
	return (ERROR);
}
