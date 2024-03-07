/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:42:24 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:21:16 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	compteur;
	size_t	len_src;
	size_t	len_dest;
	size_t	tmp;

	compteur = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	tmp = ft_strlen(dst);
	if (size <= len_dest)
		return (size + len_src);
	while (src[compteur] && size > len_dest + 1)
	{
		dst[len_dest] = src[compteur];
		compteur++;
		len_dest++;
	}
	dst[len_dest] = '\0';
	return (tmp + len_src);
}
