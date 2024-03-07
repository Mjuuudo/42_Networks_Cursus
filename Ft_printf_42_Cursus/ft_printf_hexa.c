/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:35:20 by abait-ou          #+#    #+#             */
/*   Updated: 2024/01/18 13:35:22 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(unsigned long int code)
{
	int		total;
	char	*values;

	total = 0;
	values = "0123456789abcdef";
	if (code < 16)
	{
		total += write(1, (values + code), 1);
	}
	else if (code >= 16)
	{
		total += ft_printf_hexa(code / 16);
		total += ft_printf_hexa(code % 16);
	}
	return (total);
}
