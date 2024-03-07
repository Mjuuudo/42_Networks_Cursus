/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_Uhexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:35:48 by abait-ou          #+#    #+#             */
/*   Updated: 2024/01/18 13:35:50 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uhexa(unsigned long int code)
{
	int		total;
	char	*values;

	total = 0;
	values = "0123456789ABCDEF";
	if (code < 16)
	{
		total += write(1, (values + code), 1);
	}
	else if (code >= 16)
	{
		total += ft_printf_uhexa(code / 16);
		total += ft_printf_uhexa(code % 16);
	}
	return (total);
}
