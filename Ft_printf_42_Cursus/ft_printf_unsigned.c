/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:36:00 by abait-ou          #+#    #+#             */
/*   Updated: 2024/01/18 13:36:02 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_unsigned(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 0 && n < 10)
		counter += ft_putchar(n + '0');
	else
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putnbr(n % 10);
	}
	return (counter);
}
