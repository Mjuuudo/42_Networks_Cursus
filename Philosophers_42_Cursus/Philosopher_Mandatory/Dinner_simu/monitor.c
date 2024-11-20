/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:02:18 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/20 20:42:46 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	deadornot(t_table *table, int counter)
{
	pthread_mutex_lock(&table->eat);
	if ((get_time() - table->philos[counter].last_meal >= table->time_to_die)
		&& table->philos[counter].eating == 0)
	{
		pthread_mutex_unlock(&table->eat);
		return (1);
	}
	pthread_mutex_unlock(&table->eat);
	return (0);
}

static int	check_death(t_table *table)
{
	int	counter;

	counter = 0;
	while (counter < table->philos_number)
	{
		if (deadornot(table, counter))
		{
			pthread_mutex_lock(&table->death);
			pthread_mutex_lock(&table->print);
			table->dead = 1;
			table->end_simu = 1;
			printf("%lld %d is died\n", ft_timestamp(table),
				table->philos[counter].philo_id);
			pthread_mutex_unlock(&table->print);
			pthread_mutex_unlock(&table->death);
			return (1);
		}
		counter++;
	}
	return (0);
}

static int	check_full(t_table *table)
{
	int	counter;
	int	philos;

	if (table->meals_number == -1)
		return (0);
	philos = 0;
	counter = 0;
	while (counter < table->philos_number)
	{
		if (table->philos[counter].meals_eaten == table->meals_number)
			philos++;
		counter++;
	}
	if (philos == table->philos_number)
		return (1);
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	ft_usleep(2, &table->philos[0]);
	while (1)
	{
		if (check_death(table) == 1 || check_full(table) == 1)
			break ;
		ft_usleep(5, &table->philos[0]);
	}
	pthread_mutex_lock(&table->death);
	table->dead = 1;
	table->end_simu = 1;
	pthread_mutex_unlock(&table->death);
	return (NULL);
}
