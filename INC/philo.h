/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:18 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/09 18:39:47 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

enum	e_status
{
	EAT = 1,
	SLEEP = 2,
	THINK = 3
};

typedef struct s_input {
	int	philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	amount_eat;
}	t_input;

typedef struct s_vars {
	bool			death_status;
	bool			first_death;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}	t_vars;

typedef struct s_philos {
	int					philo_number;
	int					left_fork;
	int					right_fork;
	int					status;
	t_input				input;
	t_vars				*vars;
	unsigned long long	start_time;
	unsigned long long	last_time_eaten;
}	t_philos;

/*
	PHILO
*/

int					start_thread(t_philos *philos);

int					setup_mutex(t_philos *philos);

void				*start(void *arg);

unsigned long long	get_time(void);

int					get_current_time(t_philos *philos);

/*
	PHASES PHILOS
*/

void				start_think(t_philos *philos);

void				start_sleep(t_philos *philos);

void				start_eat(t_philos *philos);

void				start_death(t_philos *philos);

/*
	UTILS
*/

int					ft_atoi(const char *str);

#endif
