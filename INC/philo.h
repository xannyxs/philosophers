/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 14:09:18 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/13 16:03:28 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <signal.h>

# define SUCCES 0
# define ERROR 1

enum	e_status
{
	EAT = 1,
	SLEEP = 2,
	THINK = 3,
	DEATH = 4,
	GRAB_LEFT = 5,
	GRAB_RIGHT = 6
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
	pthread_mutex_t	*protect_printf;
}	t_vars;

typedef struct s_philos {
	int				philo_number;
	int				left_fork;
	int				right_fork;
	int				status;
	t_input			input;
	t_vars			*vars;
	unsigned long	start_time;
	unsigned long	last_time_eaten;
}	t_philos;

/*
	PHILO
*/

int				start_thread(t_philos *philos);

int				setup_mutex(t_philos *philos);

void			*start(void *arg);

int				get_current_time(t_philos *philos);

unsigned long	get_time(void);

int				error_msg(int error_num);

int				error_complex_msg(int error_num, t_philos *philos);

/*
	PHASES PHILOS
*/

void			start_think(t_philos *philos);

void			start_sleep(t_philos *philos);

void			start_eat(t_philos *philos);

void			start_death(t_philos *philos);

/*
	UTILS
*/

int				ft_atoi(const char *str);

void			ft_free_str_arr(char **arr);

void			ft_free_mutex_arr(pthread_mutex_t **arr);

void			print_wrap(t_philos *philos);

void			u_better_sleep(t_philos *philos, unsigned long ms);

bool			is_philo_dying(t_philos *philos);

int				destroy_all_mutex(t_philos *philos);

int				destroy_fork_mutex(t_philos *philos);

/*
	PRINT
*/

void			print_eat(t_philos *philos);

void			print_right_fork(t_philos *philos);

void			print_left_fork(t_philos *philos);

#endif
