/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_thread.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:19:31 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/03 19:50:37 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_thread(t_vars *vars)
{
	int	i;
	int	err;

	i = 0;
	vars->threads = malloc(sizeof(pthread_t) * vars->input.philos);
	if (vars->threads == NULL)
	{
		free(vars->threads);
		exit(-1);
	}
	while (true)
	{
		err = pthread_create(&vars->threads[i], NULL, (void *)start, &vars[i]);
		if (err != 0)
		{
			pthread_exit(NULL);
			exit(err);
		}
		i++;
		sleep(1);
		if (i >= vars->input.philos)
			i = 0;
	}
}
