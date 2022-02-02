/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:18 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/02 19:29:17 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_input {
	int	philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
}				t_input;

typedef struct s_vars {
	t_input			input;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}			t_vars;

/*
    PHILO
*/

/*
    UTILS
*/

int		ft_atoi(const char *str);

#endif