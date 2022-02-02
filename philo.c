/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:13 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/02 19:21:02 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(int i, t_vars *vars)
{
	pthread_mutex_lock(&vars->forks[i]);
	pthread_mutex_lock(&vars->forks[i + 1]);
	printf("%d is eating\n", i);
	pthread_mutex_unlock(vars->forks);
}

void	*start(t_vars *vars)
{
	static int	i;

	i = 1;
	while (true)
	{
		if (i >= vars->input.philos)
			i = 1;
		eat(i, vars);
		i++;
	}
	return (NULL);
}

void	create_philo(t_vars *vars)
{
	int				i;
	int				err;

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
	i = 0;
	vars->threads = malloc(sizeof(pthread_t) * vars->input.philos);
	while (i < vars->input.philos)
	{
		err = pthread_create(vars->threads, NULL, (void *)start, vars);
		if (err != 0)
		{
			pthread_exit(NULL);
			exit(err);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_vars		vars;

	i = 0;
	if (argc == 5)
	{
		vars.input.philos = ft_atoi(argv[1]);
		vars.input.time_die = ft_atoi(argv[2]);
		vars.input.time_eat = ft_atoi(argv[3]);
		vars.input.time_sleep = ft_atoi(argv[4]);
		create_philo(&vars);
		pthread_exit(NULL);
	}
	return (0);
}
