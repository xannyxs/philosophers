/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/08 17:09:55 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start(t_vars *vars)
{
	// pthread_mutex_lock(&vars->forks[vars->philos.left_fork]);
	pthread_mutex_lock(vars->forks);
	printf("Lock 1: %d\n", vars->philos.left_fork);
	printf("Lock 2: %d\n", vars->philos.right_fork);
	if ((vars->philos.philo_number % 2) == 0)
		printf("%d is eating\n", vars->philos.philo_number);
	else
		printf("%d is sleeping\n", vars->philos.philo_number);
	pthread_mutex_unlock(vars->forks);
	// pthread_mutex_unlock(&vars->forks[vars->philos.right_fork]);
	return (NULL);
}

void    start_thread(t_vars *vars)
{
	int	i;
	// int	err;

	i = 0;
	while (i < vars->input.philos)
	{
		vars[i].threads = malloc(sizeof(pthread_t));
		if (vars[i].threads == NULL)
			exit(-1);
		i++;
	}
	i = 0;
	while (i < vars->input.philos)
	{
		pthread_create(vars[i].threads, NULL, (void *) start, &vars[i]);
		usleep(1000);
		i++;
	}
}
