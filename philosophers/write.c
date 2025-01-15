/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:04:45 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/01/15 14:09:08 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo,
							 long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo->table))
		printf("%-6ld %d a pris la fourchette %d\n", elapsed, philo->id,
				philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simulation_finished(philo->table))
		printf("%-6ld %d a pris la fourchette %d\n", elapsed, philo->id,
				philo->second_fork->fork_id);
	else if (EATING == status && !simulation_finished(philo->table))
		printf("%-6ld %d mange pour la %ld fois\n", elapsed, philo->id,
				philo->meals_counter);
	else if (SLEEPING == status && !simulation_finished(philo->table))
		printf("%-6ld %d dort\n", elapsed, philo->id);
	else if (THINKING == status && !simulation_finished(philo->table))
		printf("%-6ld %d pense\n", elapsed, philo->id);
	else if (DIED == status && !simulation_finished(philo->table))
		printf("%-6ld %d est mort\n", elapsed, philo->id);
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
			printf("%-6ld %d a pris une fourchette\n", elapsed, philo->id);
		else if (EATING == status && !simulation_finished(philo->table))
			printf("%-6ld %d mange\n", elapsed, philo->id);
		else if (SLEEPING == status && !simulation_finished(philo->table))
			printf("%-6ld %d dort\n", elapsed, philo->id);
		else if (THINKING == status && !simulation_finished(philo->table))
			printf("%-6ld %d pense\n", elapsed, philo->id);
		else if (DIED == status && !simulation_finished(philo->table))
			printf("%-6ld %d est mort\n", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
