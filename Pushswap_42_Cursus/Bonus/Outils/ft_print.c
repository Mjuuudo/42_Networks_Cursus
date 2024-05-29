/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:52:42 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/23 20:18:24 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
