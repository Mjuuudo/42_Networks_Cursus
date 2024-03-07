/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:35:35 by abait-ou          #+#    #+#             */
/*   Updated: 2024/01/18 13:35:37 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(long text)
{
	int	counter;

	counter = 0;
	counter += ft_putstr("0x");
	counter += ft_printf_hexa(text);
	return (counter);
}
