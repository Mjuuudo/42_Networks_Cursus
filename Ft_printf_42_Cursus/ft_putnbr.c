/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:37:00 by abait-ou          #+#    #+#             */
/*   Updated: 2024/01/18 13:44:47 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_nblen(int nb)
{
	unsigned int	number;
	int				i;

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
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;
	int	nb;

	nb = n;
	i = 0;
	if (nb == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
	i += my_nblen(n);
	return (i);
}
