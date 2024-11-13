/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:28:49 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/13 18:30:07 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int	ft_deathcheck(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (philo->table->dead != 0)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

void	print_messag(long time, int id, char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	if (!ft_deathcheck(philo))
		printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->print_lock);
}

long long	ft_timestamp(t_table *table)
{
	return (get_time() - table->start_simu);
}
