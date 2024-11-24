/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:42:28 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/24 16:28:24 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_takeforks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	ft_select_forks(philo, &first_fork, &second_fork);
	(pthread_mutex_lock(first_fork), philo->attach = 1);
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Right Fork Taken 🍽️", philo);
	pthread_mutex_lock(philo->death_lock);
	if (philo->table->dead)
		return ((pthread_mutex_unlock(philo->death_lock),
				pthread_mutex_unlock(first_fork)), 0);
	pthread_mutex_unlock(philo->death_lock);
	if (philo->table->philos_number == 1)
	{
		ft_usleep(philo->table->time_to_die, philo);
		return (pthread_mutex_unlock(first_fork), 0);
	}
	pthread_mutex_lock(second_fork);
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Left Fork Taken 🍽️", philo);
	return (1);
}

void	ft_releaseforks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->first_fork < philo->seconde_fork)
	{
		first_fork = philo->first_fork;
		second_fork = philo->seconde_fork;
	}
	else
	{
		first_fork = philo->seconde_fork;
		second_fork = philo->first_fork;
	}
	ft_select_forks(philo, &first_fork, &second_fork);
	pthread_mutex_unlock(first_fork);
	philo->attach = 0;
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Right Fork Released 🍽️", philo);
	pthread_mutex_unlock(second_fork);
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Left Fork Released 🍽️", philo);
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
	print_messag(ft_timestamp(philo->table), philo->philo_id,
		"Is Sleeping ⋆｡°•☁️", philo);
	if (ft_usleep(philo->table->time_to_sleep, philo))
		return (0);
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
	print_messag(ft_timestamp(philo->table), philo->philo_id, "Is Thinking 🤔",
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
	print_messag(ft_timestamp(philo->table), philo->philo_id, "Is eating 🍿",
		philo);
	if (ft_usleep(philo->table->time_to_eat, philo))
		return (ft_releaseforks(philo), 0);
	ft_releaseforks(philo);
	return (1);
}
