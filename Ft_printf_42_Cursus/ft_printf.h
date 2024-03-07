/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:35:07 by abait-ou          #+#    #+#             */
/*   Updated: 2024/01/18 13:35:11 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
void	check_formats(char indicator, va_list ap, int *counter);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		my_nblen(int n);
int		my_unsigned(unsigned int n);
int		ft_printf_hexa(unsigned long int code);
int		ft_printf_uhexa(unsigned long int code);
int		ft_printf_pointer(long text);

#endif
