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

static int ft_takeforks(t_philo *philo) {
    pthread_mutex_lock(philo->death_lock);
    if (philo->table->dead) {
        pthread_mutex_unlock(philo->death_lock);
        return 0;
    }
    pthread_mutex_unlock(philo->death_lock);
    
    pthread_mutex_lock(philo->first_fork);
    print_messag(ft_timestamp(philo->table), philo->philo_id, "Right Fork Taken", philo);
    
    pthread_mutex_lock(philo->death_lock);
    if (philo->table->dead) {
        pthread_mutex_unlock(philo->death_lock);
        pthread_mutex_unlock(philo->first_fork);
        return 0;
    }
    pthread_mutex_unlock(philo->death_lock);
    if (philo->table->philos_number == 1)
    {
        ft_usleep(philo->table->time_to_die);
        return (0);
    }
    pthread_mutex_lock(philo->seconde_fork);
    print_messag(ft_timestamp(philo->table), philo->philo_id, "Left Fork Taken", philo);
    
    return 1;
}

static void ft_releaseforks(t_philo *philo)
{
    pthread_mutex_unlock(philo->first_fork);
    print_messag(ft_timestamp(philo->table), philo->philo_id, "Right Fork Released", philo);
    pthread_mutex_unlock(philo->seconde_fork);
    print_messag(ft_timestamp(philo->table), philo->philo_id, "Left Fork Released", philo);
}



static int ft_sleep(t_philo *philo)
{
    pthread_mutex_lock(philo->death_lock);
    if (philo->table->dead == 1)
    {
        pthread_mutex_unlock(philo->death_lock);
        return (0);
    }
    pthread_mutex_unlock(philo->death_lock);
    print_messag(ft_timestamp(philo->table), philo->philo_id, "Is Sleeping", philo);
    ft_usleep(philo->table->time_to_sleep);
    return (1);
}

static int ft_think(t_philo *philo)
{
    pthread_mutex_lock(philo->death_lock);
    if (philo->table->dead == 1)
    {
        pthread_mutex_unlock(philo->death_lock);
        return (0);
    }
    pthread_mutex_unlock(philo->death_lock);
    print_messag(ft_timestamp(philo->table), philo->philo_id, "Is Thinking", philo);
    return (1);
}

static int eat(t_philo *philo) {
    if (!ft_takeforks(philo))
        return 0;
    
    pthread_mutex_lock(philo->eat_lock);
    philo->eating = 1;
    philo->last_meal = get_time();
    philo->meals_eaten++;
    philo->eating = 0;
    pthread_mutex_unlock(philo->eat_lock);
    print_messag(ft_timestamp(philo->table), philo->philo_id, "Is eating", philo);
    ft_usleep(philo->table->time_to_eat);
    
    ft_releaseforks(philo);
    return 1;
}


void *ft_routine(void *arg) {
    t_philo *philo;
    philo = (t_philo *)arg;
    
    
    if (philo->philo_id % 2 == 0)
        ft_usleep(1);
    
    while (1) {
        
       
        pthread_mutex_lock(philo->death_lock);
        if (philo->table->dead == 1) {
            pthread_mutex_unlock(philo->death_lock);
            break;
        }
        pthread_mutex_unlock(philo->death_lock);
        
        if (!eat(philo))  
            break;
        if (!ft_sleep(philo))
             break;  // Modified to return status  
        if (!ft_think(philo))
            break; // Modified to return status    
        //  printf("flag ****** %d ***** %d \n", philo->table->dead, philo->table->end_simu);
    }
    
    return NULL;
}

