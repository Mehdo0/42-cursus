/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:26:26 by mehdi             #+#    #+#             */
/*   Updated: 2025/01/11 12:23:54 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <err.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_table t_table;

typedef enum s_opcode
{
	LOCK,
	CREATE,
	UNLOCK,
	JOIN,
	DESTROY,
	DETACH,
	INIT
}	t_opcode;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}		t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*right_fork;
	t_fork		*left_fork;
	pthread_t	thread_id;
	t_table		table;
}		t_philo;

typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_eat;
	long	nbr_limits_meals;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}		t_table;

// **utils**
void	error_exit(const char *error);
void	safe_malloc(size_t bytes);

// **parsing**
void	parse_input(t_table *table, char **av);

#endif