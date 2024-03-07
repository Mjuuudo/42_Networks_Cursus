/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:55:50 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/22 13:13:19 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = dest;
	s2 = src;
	if (!s1 && !s2)
		return (NULL);
	if (s1 < s2)
	{
		while (n--)
		{
			*s1++ = *s2++;
		}
	}
	else
	{
		while (n--)
		{
			s1[n] = s2[n];
		}
	}
	return (dest);
}
