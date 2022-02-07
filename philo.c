/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:33:02 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/07 16:44:55 by xvoorvaa      ########   odam.nl         */
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

void	setup_philo(t_vars *vars, t_input input)
{
	int	j;

	j = 0;
	while (j < input.philos)
	{
		vars[j].input = input;
		vars[j].philos.philo_number = j;
		vars[j].philos.left_fork = j;
		vars[j].philos.right_fork = j + 1;
		j++;
	}
}

int	main(int argc, char *argv[])
{
	t_input	input;
	t_vars	*vars;

	if (argc != 5 && argc != 6)
		return (1);
	convert_input(argv, &input);
	vars->philos = malloc(sizeof(t_philos) * input.philos);
	setup_philo(vars, input);
	setup_mutex(vars);
	return (0);
}