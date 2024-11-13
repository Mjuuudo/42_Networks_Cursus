/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:42:28 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/13 18:44:16 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_takeforks(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (philo->table->dead)
		return (pthread_mutex_unlock(philo->death_lock), 0);
	pthread_mutex_unlock(philo->death_lock);
	pthread_mutex_lock(philo->first_fork);
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Right Fork Taken", philo);
	pthread_mutex_lock(philo->death_lock);
	if (philo->table->dead)
		return ((pthread_mutex_unlock(philo->death_lock),
				pthread_mutex_unlock(philo->first_fork)), 0);
	pthread_mutex_unlock(philo->death_lock);
	if (philo->table->philos_number == 1)
		return (ft_usleep(philo->table->time_to_die), 0);
	pthread_mutex_lock(philo->seconde_fork);
	print_messag(ft_timestamp(philo->table), philo->philo_id, "Left Fork Taken",
		philo);
	return (1);
}

void	ft_releaseforks(t_philo *philo)
{
	pthread_mutex_unlock(philo->first_fork);
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Right Fork Released", philo);
	pthread_mutex_unlock(philo->seconde_fork);
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Left Fork Released", philo);
}

int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (philo->table->dead == 1)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->death_lock);
	print_messag(ft_timestamp(philo->table), philo->philo_id, "Is Sleeping",
		philo);
	ft_usleep(philo->table->time_to_sleep);
	return (1);
}

int	ft_think(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (philo->table->dead == 1)
	{
		pthread_mutex_unlock(philo->death_lock);
		return (0);
	}
	pthread_mutex_unlock(philo->death_lock);
	print_messag(ft_timestamp(philo->table), philo->philo_id, "Is Thinking",
		philo);
	return (1);
}

int	eat(t_philo *philo)
{
	if (!ft_takeforks(philo))
		return (0);
	pthread_mutex_lock(philo->eat_lock);
	philo->eating = 1;
	philo->last_meal = get_time();
	philo->meals_eaten++;
	philo->eating = 0;
	pthread_mutex_unlock(philo->eat_lock);
	print_messag(ft_timestamp(philo->table), philo->philo_id, "Is eating",
		philo);
	ft_usleep(philo->table->time_to_eat);
	ft_releaseforks(philo);
	return (1);
}
