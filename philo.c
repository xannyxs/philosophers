/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:13 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/03 19:55:20 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(t_vars *vars)
{
	printf("Lock 1: %d\n", vars->philos.left_fork);
	printf("Lock 2: %d\n", vars->philos.right_fork);
	pthread_mutex_lock(&vars->forks[0]);
	pthread_mutex_lock(&vars->forks[1]);
	if ((vars->philos.philo_number % 2) == 0)
		printf("%d is eating\n", vars->philos.philo_number);
	else
		printf("%d is sleeping\n", vars->philos.philo_number);
	pthread_mutex_unlock(vars->forks);
	return (NULL);
}

void	convert_all_values(char *argv[], t_input *input)
{
	input->philos = ft_atoi(argv[1]);
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
}

void	give_values(t_vars *vars, t_input input)
{
	int	i;

	i = 0;
	while (i < input.philos)
	{
		vars[i].input = input;
		vars[i].philos.left_fork = i;
		vars[i].philos.right_fork = i + 1;
		i++;
	}
	vars[i].philos.right_fork = 0;
}

int	main(int argc, char *argv[])
{
	int			i;
	t_vars		*vars;
	t_input		input;

	i = 0;
	if (argc == 5)
	{
		vars = malloc(sizeof(t_philos) * ft_atoi(argv[1]));
		if (vars == NULL)
			exit(-1);
		convert_all_values(argv, &input);
		give_values(vars, input);
		create_mutex(vars);
		while (i < input.philos)
		{
			vars[i].philos.philo_number = i;
			i++;
		}
		create_thread(vars);
		pthread_exit(NULL);
	}
	return (0);
}
