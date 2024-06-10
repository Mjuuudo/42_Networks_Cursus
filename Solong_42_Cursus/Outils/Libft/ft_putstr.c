/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:31:57 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/10 14:32:12 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	compteur;

	compteur = 0;
	if (!s)
		return ;
	while (s[compteur])
	{
		ft_putchar(s[compteur]);
		compteur++;
	}
}