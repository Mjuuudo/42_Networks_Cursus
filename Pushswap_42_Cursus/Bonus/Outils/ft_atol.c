/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:48:05 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/29 16:29:10 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	long long	number;
	int			i;
	int			sign;

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

void	avoid_norminette(t_stack_list **a, t_stack_list **b)
{
	practice(a, b);
	if (ft_checksorted(*a) && !(*b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_freelinkedlist(a);
	ft_freelinkedlist(b);
}
