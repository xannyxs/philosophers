/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:18 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/02/09 17:41:01 by xvoorvaa      ########   odam.nl         */
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
	int	amount_eat;
}	t_input;

typedef struct s_vars {
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}	t_vars;

typedef struct s_philos {
	int				philo_number;
	int				left_fork;
	int				right_fork;
	int				eaten;
	t_input			input;
	t_vars			*vars;
	struct timeval	start_tv;
	struct timeval	tv;
}	t_philos;

/*
    PHILO
*/

void	start_thread(t_philos *philos);

int		setup_mutex(t_philos *philos);

void	*start(t_philos *arg);

int		get_time(t_philos *philos);

/*
    UTILS
*/

int		ft_atoi(const char *str);

#endif