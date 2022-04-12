/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 19:11:35 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/12 15:31:40 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <sys/time.h>

static int	convert_input(char *argv[], t_input *input)
{
	input->philos = ft_atoi(argv[1]);
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	if (input->philos < 1 || input->time_die < 1 || \
		input->time_eat < 1 || input->time_sleep < 1)
		return (1);
	if (argv[5] != NULL)
	{
		input->amount_eat = ft_atoi(argv[5]);
		if (input->time_sleep < 1)
			return (1);
	}
	return (0);
}

static void	setup_philo(t_philos *philos, t_input input)
{
	int	i;

	i = 0;
	philos[0].start_time = get_time();
	while (i < input.philos)
	{
		philos[i].input = input;
		philos[i].vars = philos->vars;
		philos[i].philo_number = i;
		philos[i].left_fork = i;
		philos[i].right_fork = i + 1;
		philos[i].start_time = philos[0].start_time;
		philos[i].status = EAT;
		i++;
	}
	i--;
	philos[i].right_fork = 0;
	philos->vars->death_status = false;
	philos->vars->first_death = true;
}

int	main(int argc, char *argv[])
{
	int			err;
	t_input		input;
	t_philos	*philos;

	if (argc > 6 || argc < 5)
		return (1);
	err = convert_input(argv, &input);
	if (err != 0)
		return (1);
	philos = malloc(sizeof(t_philos) * input.philos);
	if (philos == NULL)
		return (1);
	philos->vars = malloc(sizeof(t_vars));
	if (philos->vars == NULL)
		return (1);
	setup_philo(philos, input);
	err = setup_mutex(philos);
	if (err != 0)
		return (1);
	err = start_thread(philos);
	if (err != 0)
		return (1);
	return (0);
}
