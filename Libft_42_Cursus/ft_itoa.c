/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:29:33 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/30 18:39:39 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_nblen(int nb)
{
	unsigned int	i;
	unsigned int	number;

	i = 0;
	if (nb < 0)
	{
		number = nb * -1;
		i++;
	}
	else if (nb > 0)
		number = nb;
	else
		return (1);
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return ((int)i);
}

char	*ft_itoa(int n)
{
	int				nbr_len;
	int				var;
	char			*result;
	unsigned int	nb;

	var = -1;
	nbr_len = my_nblen(n);
	result = malloc(sizeof(char) * (nbr_len + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		nb = -n;
		result[0] = '-';
		var = 0;
	}
	else
		nb = n;
	result[nbr_len--] = '\0';
	while (nbr_len > var)
	{
		result[nbr_len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
