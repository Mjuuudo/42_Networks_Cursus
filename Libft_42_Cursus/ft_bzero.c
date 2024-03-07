/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:22:34 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/09 11:19:35 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t	compteur;

	compteur = 0;
	while (compteur < n)
	{
		((char *)dst)[compteur] = 0;
		compteur++;
	}
}
