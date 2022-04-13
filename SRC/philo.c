/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 19:11:35 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/13 16:03:21 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <sys/time.h>

#define MORE_ARGC 1
#define NON_VALID_DIGITS 2
#define MALLOC_ERR 3

static int	convert_input(char *argv[], t_input *input)
{
	input->philos = ft_atoi(argv[1]);
	input->time_die = ft_atoi(argv[2]);
	input->time_eat = ft_atoi(argv[3]);
	input->time_sleep = ft_atoi(argv[4]);
	if (input->philos < 1 || input->time_die < 1 || \
		input->time_eat < 1 || input->time_sleep < 1)
		return (ERROR);
	if (argv[5] != NULL)
	{
		input->amount_eat = ft_atoi(argv[5]);
		if (input->time_sleep < 1)
			return (ERROR);
	}
	else
		input->amount_eat = -2;
	return (SUCCES);
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
		philos[i].status = GRAB_LEFT;
		i++;
	}
	i--;
	philos[i].right_fork = 0;
	philos->vars->death_status = false;
	philos->vars->first_death = true;
}

static void	free_all(t_philos *philos)
{
	free(philos->vars->protect_printf);
	free(philos->vars->forks);
	free(philos->vars->threads);
	free(philos->vars);
	free(philos);
}

int	main(int argc, char *argv[])
{
	t_input		input;
	t_philos	*philos;

	philos = NULL;
	if (argc > 6 || argc < 5)
		return (error_msg(MORE_ARGC));
	if (convert_input(argv, &input))
		return (error_msg(NON_VALID_DIGITS));
	philos = malloc(sizeof(t_philos) * input.philos);
	if (!philos)
		return (error_msg(MALLOC_ERR));
	philos->vars = malloc(sizeof(t_vars));
	if (!philos->vars)
		return (error_complex_msg(4, philos));
	setup_philo(philos, input);
	if (setup_mutex(philos))
		return (ERROR);
	if (start_thread(philos))
		return (ERROR);
	free_all(philos);
	return (0);
}
