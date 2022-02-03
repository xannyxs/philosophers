/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:18 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/03 17:45:44 by xvoorvaa      ########   odam.nl         */
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


typedef struct s_philos {
	int	philo_number;
	int	left_fork;
	int	right_fork;
}				t_philos;

typedef struct s_input {
	int	philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
}				t_input;

typedef struct s_vars {
	t_input			input;
	t_philos		philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}			t_vars;

/*
    PHILO
*/

void	create_thread(t_vars *vars);

void	create_mutex(t_vars *vars);

void	*start(t_vars *arg);

/*
    UTILS
*/

int		ft_atoi(const char *str);

#endif