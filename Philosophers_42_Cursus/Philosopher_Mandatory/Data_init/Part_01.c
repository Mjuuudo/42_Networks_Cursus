/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:16:45 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/07 22:16:51 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void ft_initforks(t_table *table)
{
    int counter;

    pthread_mutex_init(&table->print_mutex, NULL);
    counter = 0;
    while (counter < table->number_of_philos)
    {
         pthread_mutex_init(&table->forks[counter].fork, NULL);
         counter++;
    }
    
}

void ft_destroyforks(t_table *table)
{
    int counter;

    pthread_mutex_destroy(&table->print_mutex);
    counter = 0;
    while (counter < table->number_of_philos)
    {
         pthread_mutex_destroy(&table->forks[counter].fork);
         counter++;
    }
    
}

void ft_threadlife(t_table *table)
{
    int counter;

    counter = 0;
    while (counter < table->number_of_philos)
    {
        table->philos[counter].philo_id = counter + 1;
        if (table->meals_left > -1)
            continue ;
        table->philos[counter].flag_full_or_not = 0;
        table->philos[counter].table = table;
        table->philos[counter].first_fork = &table->forks[counter];
        table->philos[counter].second_fork = &table->forks[(counter + 1) % table->number_of_philos]; 
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
        if (pthread_join(table->philos[counter].thread, NULL) != 0 )
            exit(1);
        counter++;
    }
} 

void ft_inittable(t_table *table, pthread_t *monitor)
{

    if (pthread_create(monitor, NULL, &ft_monitor, NULL) != 0)
        exit (1);
    if (pthread_join(monitor, NULL) != 0)
        exit (1);
    ft_initforks(table);
    ft_threadlife(table);
    ft_threadjoin(table);
    ft_destroyforks(table); 
}

