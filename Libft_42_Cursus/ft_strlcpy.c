/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:58:01 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/23 14:29:40 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	compteur;
	size_t	src_len;

	compteur = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size != 0)
	{
		while (src[compteur] && compteur < (size - 1))
		{
			dest[compteur] = src[compteur];
			compteur++;
		}
	}
	dest[compteur] = '\0';
	return (src_len);
}
