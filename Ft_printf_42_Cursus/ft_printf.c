/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:49 by abait-ou          #+#    #+#             */
/*   Updated: 2024/01/18 13:34:56 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_formats(char indicator, va_list ap, int *counter)
{
	long	va_arg_holder;

	if (indicator == 'd' || indicator == 'i')
		*counter += ft_putnbr(va_arg(ap, int));
	else if (indicator == 'c')
		*counter += ft_putchar(va_arg(ap, int));
	else if (indicator == 's')
		*counter += ft_putstr(va_arg(ap, char *));
	else if (indicator == 'x')
		*counter += ft_printf_hexa(va_arg(ap, unsigned int));
	else if (indicator == 'X')
		*counter += ft_printf_uhexa(va_arg(ap, unsigned int));
	else if (indicator == 'u')
		*counter += my_unsigned(va_arg(ap, unsigned int));
	else if (indicator == 'p')
	{
		va_arg_holder = va_arg(ap, long);
		if (va_arg_holder == 0)
			*counter += ft_putstr("(nil)");
		else
			*counter += ft_printf_pointer(va_arg_holder);
	}
	else if (indicator == '%')
		*counter += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	int		total;
	int		compteur;
	va_list	ap;

	total = 0;
	compteur = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[compteur])
	{
		if (format[compteur] == '%')
		{
			compteur++;
			check_formats((format[compteur]), ap, &total);
		}
		else
		{
			total += ft_putchar(format[compteur]);
		}
		compteur++;
	}
	va_end(ap);
	return (total);
}
