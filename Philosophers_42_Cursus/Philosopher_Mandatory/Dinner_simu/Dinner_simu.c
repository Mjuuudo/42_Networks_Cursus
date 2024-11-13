/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dinner_simu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:46:32 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/13 18:45:59 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	threadscreate(t_table *table)
{
	int			counter;
	pthread_t	monitor;

	counter = 0;
	if (pthread_create(&monitor, NULL, &ft_monitor, table) != 0)
		(ft_mutexdestroy(table), exit(0));
	while (counter < table->philos_number)
	{
		if (pthread_create(&table->philos[counter].thread, NULL, &ft_routine,
				&table->philos[counter]) != 0)
			(ft_mutexdestroy(table), exit(0));
		counter++;
	}
	counter = 0;
	if (pthread_join(monitor, NULL) != 0)
		(ft_mutexdestroy(table), exit(0));
	while (counter < table->philos_number)
	{
		if (pthread_join(table->philos[counter].thread, NULL) != 0)
			(ft_mutexdestroy(table), exit(0));
		counter++;
	}
}

void	ft_mutexdestroy(t_table *table)
{
	int	counter;

	pthread_mutex_destroy(&table->death);
	pthread_mutex_destroy(&table->eat);
	pthread_mutex_destroy(&table->print);
	counter = 0;
	while (counter < table->philos_number)
	{
		pthread_mutex_destroy(&table->forks[counter++].fork);
	}
}

void	ft_dinner(t_table *table)
{
	threadscreate(table);
}
