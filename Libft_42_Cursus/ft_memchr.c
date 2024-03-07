/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:28:32 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/09 11:26:30 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		val;
	size_t				i;

	p = str;
	val = c;
	i = 0;
	while (i < n)
	{
		if (p[i] == val)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}
