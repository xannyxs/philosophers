/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/09 15:22:59 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start(t_philos *philos)
{
	while (true)
	{
		pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
		pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
		if (philos->eaten != true)
		{
			printf("%d is eating\n", philos->philo_number);
			philos->eaten = true;
		}
		else
		{
			printf("%d is sleeping\n", philos->philo_number);
			philos->eaten = false;
		}
		pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
		pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
		usleep(10000000);
	}
	return (NULL);
}

/*

*/

void    start_thread(t_philos *philos)
{
	int	i;
	// int	err;

	i = 0;
	philos->vars->threads = malloc(sizeof(pthread_t) * philos->input.philos);
	if (philos->vars->threads == NULL)
		exit(-1);
	while (i < philos->input.philos)
	{
		pthread_create(philos[i].vars->threads, NULL, (void *) start, &philos[i]);
		i++;
	}
	i = 0;
	while (i < philos->input.philos)
	{
		pthread_join(*philos[i].vars->threads, NULL);
		i++;
	}
}
