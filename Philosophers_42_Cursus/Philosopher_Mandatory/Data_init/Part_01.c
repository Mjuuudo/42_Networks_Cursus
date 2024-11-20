/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:16:45 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/20 17:09:21 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_forksinit(t_table *table)
{
	int	counter;

	counter = 0;
	if (pthread_mutex_init(&table->death, NULL) != 0)
		(ft_mutexdestroy(table), exit(0));
	if (pthread_mutex_init(&table->eat, NULL) != 0)
		(ft_mutexdestroy(table), exit(0));
	if (pthread_mutex_init(&table->print, NULL) != 0)
		(ft_mutexdestroy(table), exit(0));
	while (counter < table->philos_number)
	{
		if (pthread_mutex_init(&table->forks[counter].fork, NULL) != 0)
			(ft_mutexdestroy(table), exit(0));
		counter++;
	}
}

void	ft_philosinit(t_table *table)
{
	int	counter;

	counter = 0;
	while (counter < table->philos_number)
	{
		table->philos[counter].philo_id = counter + 1;
		table->philos[counter].meals_eaten = 0;
		table->philos[counter].last_meal = get_time();
		table->philos[counter].death_lock = &table->death;
		table->philos[counter].eat_lock = &table->eat;
		table->philos[counter].print_lock = &table->print;
		table->philos[counter].first_fork = &table->forks[counter].fork;
        table->philos[counter].seconde_fork = 
            &table->forks[(counter + 1) % table->philos_number].fork;
		table->philos[counter].table = table;
		table->philos[counter].eating = 0;
		counter++;
	}

	
}

void	ft_inittable(t_table *table)
{
	ft_forksinit(table);
	ft_philosinit(table);
	table->dead = 0;
}
