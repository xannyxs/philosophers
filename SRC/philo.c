/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 19:11:35 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/16 19:12:21 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	convert_input(char *argv[], t_input *input)
{
	input->philos = ft_atoi(argv[1]);
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		input->amount_eat = ft_atoi(argv[5]);
}

void	setup_philo(t_philos *philos, t_input input)
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
		if ((philos[i].philo_number % 2) == 0)
			philos[i].status = EAT;
		else
			philos[i].status = SLEEP;
		i++;
	}
	i--;
	philos[i].right_fork = 0;
}

int	main(int argc, char *argv[])
{
	t_input		input;
	t_philos	*philos;

	if (argc != 5 && argc != 6)
		return (1);
	convert_input(argv, &input);
	philos = malloc(sizeof(t_philos) * input.philos);
	philos->vars = malloc(sizeof(t_vars));
	setup_philo(philos, input);
	setup_mutex(philos);
	start_thread(philos);
	return (0);
}