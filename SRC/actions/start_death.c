/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_death.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 17:11:44 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/06 20:26:42 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <stdlib.h>

void	start_death(t_philos *philos)
{
	(void) philos->last_time_eaten;
	exit(1);
}
