/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:28:49 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/24 20:40:28 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_usleep(long long milliseconds, t_philo *philo)
{
	size_t	start;

	start = get_time();
	while ((long long)(get_time() - start) < milliseconds)
	{
		if (philo->table->dead == 1)
			return (1);
		usleep(500);
	}
	return (0);
}

int	ft_deathcheck(t_philo *philo)
{
	if (philo->table->dead != 0)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (1);
	}
	return (0);
}

void	print_messag(long time, int id, char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	pthread_mutex_lock(philo->print_lock);
	if (philo->table->dead == 0)
		printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_unlock(philo->death_lock);
}

long long	ft_timestamp(t_table *table)
{
	return (get_time() - table->start_simu);
}

int	ft_select_forks(t_philo *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philo->first_fork < philo->seconde_fork)
	{
		*first_fork = philo->first_fork;
		*second_fork = philo->seconde_fork;
	}
	else
	{
		*first_fork = philo->seconde_fork;
		*second_fork = philo->first_fork;
	}
	return (1);
}
