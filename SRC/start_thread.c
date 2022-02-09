/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 11:37:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/09 17:49:45 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start(t_philos *philos)
{
	while (true)
	{
		philos->tv.tv_usec = get_time(philos);
		if (philos->eaten != true)
		{
			pthread_mutex_lock(&philos->vars->forks[philos->left_fork]);
			pthread_mutex_lock(&philos->vars->forks[philos->right_fork]);
			printf("%d | %d is eating\n", philos->tv.tv_usec, philos->philo_number);
			philos->eaten = true;
			usleep(philos->input.time_eat * 1000);
			pthread_mutex_unlock(&philos->vars->forks[philos->left_fork]);
			pthread_mutex_unlock(&philos->vars->forks[philos->right_fork]);
			printf("%d gave back a fork\n", philos->philo_number);
		}
		else
		{
			printf("%d | %d is sleeping\n", philos->tv.tv_usec, philos->philo_number);
			usleep(philos->input.time_sleep * 1000);
			philos->eaten = false;
		}
		usleep(1000000);
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
