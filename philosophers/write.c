/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:04:45 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/01/14 11:51:31 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo,
							 long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf("%-6ld %d a pris la fourchette %d", elapsed, philo->id,
				philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf("%-6ld %d a pris la fourchette %d", elapsed, philo->id,
				philo->second_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%-6ld %d mange pour la %ld", elapsed, philo->id,
				philo->meals_counter);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%-6ld %d dort", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%-6ld %d pense", elapsed, philo->id);
	else if (DIED == status && !simulation_finished(philo->table))
		printf("%-6ld %d est mort", elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;
	
	elapsed = gettime(MILLISECOND) - philo->table->start_simulation;
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo->table))
			printf("%-6ld %d a pris une fourchette", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf("%-6ld %d mange", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf("%-6ld %d dort", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf("%-6ld %d pense", elapsed, philo->id);
		else if (DIED == status && !simulation_finished(philo->table))
			printf("%-6ld %d est mort", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
