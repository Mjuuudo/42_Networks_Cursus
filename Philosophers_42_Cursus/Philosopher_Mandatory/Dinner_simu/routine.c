/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:41:21 by marvin            #+#    #+#             */
/*   Updated: 2024/11/20 16:29:28 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		ft_usleep(60, philo);
	// printf("Philosopher %d: first_fork=%p, seconde_fork=%p\n", 
    //        philo->philo_id, 
    //        (void*)philo->first_fork, 
    //        (void*)philo->seconde_fork);
	while (1)
	{
		pthread_mutex_lock(philo->death_lock);
		if (philo->table->dead == 1)
		{
			pthread_mutex_unlock(philo->death_lock);
			break ;
		}
		pthread_mutex_unlock(philo->death_lock);
		if (!eat(philo))
			break ;
		if (!ft_sleep(philo))
			break ;
		if (!ft_think(philo))
			break ;
		// ft_usleep(1, philo);
	}
	// printf("%d \n", philo->philo_id);
	return (NULL);
}
