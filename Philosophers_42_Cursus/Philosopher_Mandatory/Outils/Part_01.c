/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:21:18 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/07 17:06:47 by abait-ou         ###   ########.fr       */
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

long int	get_time(void)
{
	struct timeval	tv;
	long int		time_in_micro;

	gettimeofday(&tv, NULL);
	time_in_micro = tv.tv_usec;
	return (time_in_micro);
}


void	ft_usleep(long int time_to_wait)
{
	long int	start;
	long int	current;

	start = get_time();
	while (1)
	{
		current = get_time();
		if ((current - start) >= time_to_wait)
			return ;
		usleep(100);
	}
}