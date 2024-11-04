/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:16:45 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/03 18:09:17 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"


void  ft_initthreads(t_table *table)
{
    int counter;

    counter = 0;
    pthread_mutex_init(&table->print_mutex, NULL);
    while (counter < table->number_of_philos)
    {
        table->philos[counter].philo_id = counter + 1;
        table->philos[counter].table = table;
        table->philos[counter].flag_full_or_not = 0;
        table->philos[counter].first_fork = &table->forks[counter];
        table->philos[counter].seconde_fork = &table->forks[(counter + 1) % table->number_of_philos];
        if (table->meals_left == -1)
            table->philos[counter].meals_number = -1;
        else
            table->philos[counter].meals_number = table->meals_left;
        table->philos[counter].last_meal = get_time();
        if (pthread_create(&table->philos[counter].thread, NULL, &ft_routine, &table->philos[counter]) != 0)
                exit (1);
        counter++;
    }
}

void ft_threadjoin(t_table *table)
{
    int counter;

    counter = 0;
    while (counter < table->number_of_philos)
    {
        pthread_join(table->philos[counter].thread, NULL);
        counter++;
    }
}

void ft_forksinit(t_table *table)
{
    int counter;
    
    counter = 0;
    while (counter < table->number_of_philos)
    {
        table->forks[counter].fork_id = counter + 1;
        pthread_mutex_init(&table->forks[counter].fork, NULL);
        counter++;
    }
    pthread_mutex_init(&table->print_mutex, NULL);
}

void  ft_inittable(t_table *table)
{
    ft_forksinit(table);
    ft_initthreads(table);
    ft_threadjoin(table);
}

