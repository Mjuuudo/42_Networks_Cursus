/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:41:21 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 13:41:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"


static int ft_arealive(t_table *table)
{
    int counter;

    counter = 0;
    while (counter < table->number_of_philos)
    {
        if ((get_time() - table->philos[counter].last_meal) > table->time_to_die)
        {
            printf("time %ld\ncurrent %ld\n",(get_time() - table->philos[counter].last_meal), table->philos[counter].last_meal);
            table->flag_end_simulation = 1;
            break ;
            printf("%d  %d died\n",(get_time() - table->philos[counter].last_meal), table->philos[counter].last_meal);
        }
        // printf("Timing %ld && Die in %d\n", (ft_gettime() - table->philos[counter].last_meal), table->time_to_die);

        counter++;
    }
    return (table->flag_end_simulation);
}

void take_forks(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->first_fork->fork);
    printf("%ld %ld Right Fork Is taken\n", (get_time() - philo->table->start_simulation), philo->philo_id);
    pthread_mutex_lock(&philo->seconde_fork->fork);
    printf("%ld %ld Left Fork Is taken\n", (get_time() - philo->table->start_simulation), philo->philo_id);
}

static void release_forks(t_philosopher *philo)
{
    
    pthread_mutex_unlock(&philo->first_fork->fork);
    printf("%ld %ld Right Fork Is taken\n", (get_time() - philo->table->start_simulation), philo->philo_id);
    pthread_mutex_unlock(&philo->seconde_fork->fork);
    printf("%ld %ld Left Fork Is taken\n", (get_time() - philo->table->start_simulation), philo->philo_id);
}

static void eat(t_philosopher *philo)
{
    take_forks(philo);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%d  %d is eating\n",  (get_time() - philo->table->start_simulation), philo->philo_id);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->table->print_mutex);
    release_forks(philo);
    ft_usleep(philo->table->time_to_eat);
}

static void sleeping(t_philosopher *philo)
{
    printf("%d  %d  is sleeping\n", (get_time() - philo->table->start_simulation), philo->philo_id);
    ft_usleep(philo->table->time_to_sleep);
}

static void think(t_philosopher *philo)
{
    printf("%d  %d  is thinking\n", (get_time() - philo->table->start_simulation) , philo->philo_id);
}

void *ft_routine(void *arg)
{
    t_philosopher *philo;

    philo = (t_philosopher *)arg;

    if (philo->philo_id % 2)
        ft_usleep(1000);
    printf("flag %d\n", philo->table->flag_end_simulation);
    while (!ft_arealive(philo->table))
    {

        if (!philo->table->flag_end_simulation)
            eat(philo);
        if (!philo->table->flag_end_simulation)
            sleeping(philo);
        if (!philo->table->flag_end_simulation)
            think(philo);
        
            
    }
    return (NULL);
}

/*
I Need To Restart The Process Of Routine Or Only Check it to get 
The Nedded Result -> 
    (Function That Checks If One Of The Philos Is Dead / 
    Funtcion To Take the Forks / Function That Ulistrate The Dinner / 
    One For RelasingThe Forks /  Another one
    For The Sleeping Action / Finnaly One For  Thinking Action)
*/