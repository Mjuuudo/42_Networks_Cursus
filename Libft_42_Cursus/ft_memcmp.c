/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:27 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/09 12:55:25 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s_str1;
	const unsigned char	*s_str2;
	size_t				i;

	s_str2 = str2;
	s_str1 = str1;
	i = 0;
	while (i < n)
	{
		if (s_str2[i] != s_str1[i])
			return (s_str1[i] - s_str2[i]);
		i++;
	}
	return (0);
}
