/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:21:18 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/13 11:43:48 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int ft_isspace(char c)
{
    if (c == 32 || c >= 9 && c <= 13)
        return (1);
    return (0);   
}
int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
long long	ft_atol(const char *str)
{
	long long	number;
    int i;
	int	sign;

	i = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	number = 0;
	while (ft_isdigit(str[i]))
	{
		number *= 10;
		number = str[i] - 48 + number;
		i++;
	}
	return (number * sign);
}

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	ft_timestamp(t_table *table)
{
	return (get_time() - table->start_simu);
}


int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

int ft_deathcheck(t_philo *philo)
{
    pthread_mutex_lock(philo->death_lock);
    if (philo->table->dead != 0)
    {
        pthread_mutex_unlock(philo->death_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->death_lock);
    return (0);
}

void print_messag(long time, int id, char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	if (!ft_deathcheck(philo))
		printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->print_lock);
	
}