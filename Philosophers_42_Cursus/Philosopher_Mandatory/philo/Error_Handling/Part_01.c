/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:14:50 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/20 15:46:21 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_caseexite01(void)
{
	printf("Error !\nCheck Your Argument Formats\n");
	exit(1);
}

void	diedexit(t_philo *philo)
{
	if (philo->attach == 1)
	{
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_unlock(philo->seconde_fork);
		philo->attach = 0;
	}
}
