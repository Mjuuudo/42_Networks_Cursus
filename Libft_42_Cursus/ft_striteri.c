/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:44:48 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/16 11:40:09 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	compteur;

	compteur = 0;
	if (s && f)
	{
		while (s[compteur])
		{
			f(compteur, &s[compteur]);
			compteur++;
		}
	}
}
