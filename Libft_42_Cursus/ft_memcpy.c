/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:44:48 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:22:28 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;
	size_t				compteur;

	str1 = (unsigned char *)dest;
	str2 = (const unsigned char *)src;
	compteur = 0;
	if (!dest && !src)
		return (dest);
	while (compteur < n)
	{
		str1[compteur] = str2[compteur];
		compteur++;
	}
	return (str1);
}
