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

static void ft_takeforks(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->first_fork->fork);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%d Toke The First Fork\n", philo->philo_id);
    pthread_mutex_unlock(&philo->table->print_mutex);
    pthread_mutex_lock(&philo->second_fork->fork);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%d Toke The Second Fork\n", philo->philo_id);
    pthread_mutex_unlock(&philo->table->print_mutex);


}

static void ft_releaseforks(t_philosopher *philo)
{
    pthread_mutex_unlock(&philo->first_fork->fork);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%d Release The First Fork\n", philo->philo_id);
    pthread_mutex_unlock(&philo->table->print_mutex);
    pthread_mutex_unlock(&philo->second_fork->fork);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%d Release The Second Fork\n", philo->philo_id);
    pthread_mutex_unlock(&philo->table->print_mutex);


}

static void ft_eat(t_philosopher *philo)
{
    long timestamp;

    timestamp = (get_time() - philo->table->start_simulation);
    ft_takeforks(philo);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%ld %d Is Eating\n", timestamp, philo->philo_id);
    pthread_mutex_unlock(&philo->table->print_mutex);
    philo->last_meal = get_time();
    ft_usleep(philo->table->time_to_eat);
    ft_releaseforks(philo);
}

static void ft_sleep(t_philosopher *philo)
{
    long timestamp;

    timestamp = (get_time() - philo->table->start_simulation);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%ld %d Is Sleeping",timestamp, philo->philo_id);
    pthread_mutex_unlock(&philo->table->print_mutex);
    ft_usleep(philo->table->time_to_sleep);
}

static void ft_think(t_philosopher *philo)
{
    long timestamp;

    timestamp = (get_time() - philo->table->start_simulation);
    pthread_mutex_lock(&philo->table->print_mutex);
    printf("%ld %d Is Thinking",timestamp, philo->philo_id);
    pthread_mutex_unlock(&philo->table->print_mutex);
}

void *ft_routine(void *arg)
{
    t_philosopher *philo;

    philo = (t_philosopher *)arg;
    if (philo->philo_id % 2)
        ft_usleep(1000);
    while (!philo->table->flag_end_simulation)
    {
        if (!philo->table->flag_end_simulation)
            ft_eat(philo);
        if (!philo->table->flag_end_simulation)
            ft_sleep(philo);
        if (!philo->table->flag_end_simulation)
            ft_think(philo);

         if (philo->table->flag_end_simulation)
            break ;
    }

}